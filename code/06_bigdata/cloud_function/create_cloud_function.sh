#!/bin/bash

gcloud services enable cloudfunctions.googleapis.com
export PUBSUB_TOPIC="iot-workshop-topic"
export REGION="europe-west1" 
gcloud functions deploy iotcore_pubsub_to_influxdb --runtime python37 --trigger-topic $PUBSUB_TOPIC --region $REGION
