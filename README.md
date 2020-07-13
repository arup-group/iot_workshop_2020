# iot_workshop_2020

Files and study material for the Arup IoT Workshop 2020

[Slides](https://docs.google.com/presentation/d/1V-FpWEgVG5IYAx1H07vVJmNFeQp_SIVyyOpq0P_QqHQ/edit#slide=id.g877fa63a13_3_504) for the workshop.

# ESP32 Controller

![ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitc-functional-overview.jpg)

![ESP32 board](https://github.com/Nicholas3388/LuaNode/raw/master/images/ESP32_dimension.png)

![ESP32 Pinout](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-36-GPIOs-updated.jpg?ssl=1)

# ESP32 software installation

[Instructions and video walkthrough](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

[GitHub ESP32 software page](https://github.com/espressif/arduino-esp32)

[ESP32 tools and documentation](https://www.espressif.com/en/products/socs/esp32/resources)

[ESP32 pinout guide](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)

* Install the [Arduino GUI](https://www.arduino.cc/en/Main/Software)
* Enter [https://dl.espressif.com/dl/package_esp32_index.json](https://dl.espressif.com/dl/package_esp32_index.json) into the “Additional Board Manager URLs” field in File > Preferences on the Arduino GUI . Then, click the “OK” button
* Restart the Arduino GUI
* Go to Tools > Board > Boards Manager
* Search for ESP32 and press install button for the “ESP32 by Espressif Systems“

## Push the example code to the ESP32

* [code/01_blink](code/01_blink)
* [code/02_analogue](code/02_analogue)
* [code/03_webserver](code/03_webserver)

# Google Cloud Platform (GCP) setup

* [Install Google Cloud SDK](https://cloud.google.com/sdk/install)
* Optional: if using Windows install the new [Windows Terminal](https://www.microsoft.com/en-gb/p/windows-terminal/9n0dx20hk701?activetab=pivot:overviewtab) application
* If you already have the GCP SDK installed, update it with `gcloud components update`
* `gcloud auth login` to authenticate the GCP command line interface

## Steps done before the workshop 

Don't do these steps as they have been done already.
They are listed for reference in case you need to create a new project.

* Create a new project `gcloud projects create PROJECT_ID`

* Set default project `gcloud config set project PROJECT_ID`

* Enable Cloud Pub/Sub `gcloud services enable pubsub.googleapis.com`

* [Enable billing](https://console.cloud.google.com/iot/) (required for Cloud IoT) 

* Enable Cloud IoT `gcloud services enable cloudiot.googleapis.com`

* Give permission to Cloud IoT Core to publish messages on Cloud Pub/Sub
    ```
    gcloud projects add-iam-policy-binding PROJECT_ID \
    --member=serviceAccount:cloud-iot@system.gserviceaccount.com \
    --role=roles/pubsub.publisher
    ```
* Create device registry and enable the MQTT Bridge and the HTTP Bridge
    ```
    gcloud iot registries create REGISTRY_NAME \
    --region=REGION_NAME \
    --event-notification-config=topic=PUBSUB_TOPIC \
    --enable-mqtt-config --enable-http-config
    ```
* Generate an Eliptic Curve (EC) ES256 private / public key pair
    ```
    openssl ecparam -genkey -name prime256v1 -noout -out iot_private.pem
    openssl ec -in iot_private.pem -pubout -out iot_public.pem
    ```

## Steps for the workshop 

### Set the active project

* `gcloud projects list` to check that the `iot-workshop-2020` is listed
* `gcloud config set project iot-workshop-2020`

### Create the IoT core topic, subscription and device
* `gcloud pubsub topics create yourname-esp32` changing `yourname` with your name
* `gcloud pubsub subscriptions create yourname-esp32-subscription --topic yourname-esp32` changing `yourname` with your name
* Create a new Cloud IoT device
    ```
    gcloud iot devices create yourname-esp32 \
    --region=europe-west1 \
    --registry=iot-workshop-2020-registry \
    --public-key="path=./iot_public.pem,type=es256"
    ```
    changing `yourname` with your name
* `openssl ec -in iot_private.pem -noout -text`
    ```
    read EC key
    Private-Key: (256 bit)
    priv:
        35:da:f1:6b:e5:c4:ec:fb:5f:0a:35:99:a0:61:e5:
        34:45:46:2c:16:2e:19:49:ed:0a:50:8e:cb:3c:1d:
        03:f2
    pub:
        04:64:4e:44:89:89:80:33:14:ea:7e:72:aa:4d:de:
        8e:e0:ac:f1:a8:6f:11:b1:2d:54:25:8b:6c:5c:8e:
        a4:02:e7:2d:2e:c4:10:66:ee:51:1e:33:cf:95:bd:
        80:00:b2:ad:44:11:4c:70:4b:38:6e:ad:86:63:80:
        03:7c:22:7c:c6
    ASN1 OID: prime256v1
    NIST CURVE: P-256
    ```

### Push the example code to the ESP32

* Install these two libraries in the Arduino software
  * [arduino-mqtt](https://github.com/256dpi/arduino-mqtt)
  * [google-cloud-iot-arduino](https://github.com/GoogleCloudPlatform/google-cloud-iot-arduino)
* [code/04_esp32_to_giotcloud](code/04_esp32_to_giotcloud)

# Data communication stack

* [BDNS](https://github.com/theodi/BDNS)
* [DB ontology](https://github.com/google/digitalbuildings/tree/master/ontology)
* [UDMI](https://github.com/faucetsdn/daq/tree/master/schemas/udmi)
* [JSON](https://www.json.org/json-en.html)
* [JWT - JSON Web Tokens](https://jwt.io/)
* [MQTT](http://mqtt.org/)

