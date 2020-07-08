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

# Google Cloud Platform (GCP) setup

* [Install Google Cloud SDK](https://cloud.google.com/sdk/install)
* If you already have the GCP SDK installed, update it with `gcloud components update`
* `gcloud auth login` to authenticate the GCP command line interface
* `gcloud projects list` to check that the `iot-workshop-2020` is listed
* `gcloud config set project iot-workshop-2020`
* ...

# Data communication stack

* [BDNS](https://github.com/theodi/BDNS)
* [DB ontology](https://github.com/google/digitalbuildings/tree/master/ontology)
* [UDMI](https://github.com/faucetsdn/daq/tree/master/schemas/udmi)
* [JSON](https://www.json.org/json-en.html)
* [MQTT](http://mqtt.org/)

