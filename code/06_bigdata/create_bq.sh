#!/bin/sh

gcloud config set project iot-workshop-2020
bq mk iot_datalake
bq mk iot_datalake.iot_table iot_table_schema.json
gsutil mb -p iot-workshop-2020 gs://iot_bucket_2020
touch tmp_test
gsutil cp tmp_test gs://iot_bucket_2020/tmp/
gcloud dataflow jobs run iot-workshop-2020-dataflow --gcs-location gs://dataflow-templates-europe-west1/latest/PubSub_Subscription_to_BigQuery --region europe-west1 --staging-location gs://iot_bucket_2020/tmp --parameters inputSubscription=projects/iot-workshop-2020/subscriptions/iot-workshop-subscription,outputTableSpec=iot-workshop-2020:iot_datalake.iot_table
