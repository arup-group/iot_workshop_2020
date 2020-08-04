#!/bin/bash

ISODATETIME=`date -u +"%Y-%m-%dT%H:%M:%SZ"`
gcloud pubsub topics publish iot-workshop-topic --message '{"version":1,"timestamp":"'$ISODATETIME'","points":{"illuminance_sensor":{"present_value":'$RANDOM'}}}' --attribute=deviceId="LPS-27"
sleep 10
gcloud functions logs read --limit 20 --region europe-west1
