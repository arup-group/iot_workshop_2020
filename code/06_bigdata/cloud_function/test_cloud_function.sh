#!/bin/bash

gcloud pubsub topics publish iot-workshop-topic --message '{"version":1,"timestamp":"2019-01-17T14:02:29.364Z","points":{"illuminance_sensor":{"pre_value":1023}}}'
gcloud functions logs read --limit 20 --region europe-west1
