#!/bin/bash

# Set defaults for the gcloud command-line tool
export ZONE=europe-west1
export PROJECT_ID=iot-workshop-2020
gcloud config set project $PROJECT_ID
gcloud config set compute/zone $ZONE

# Create a GKE cluster with one n1-standard-1 node:
gcloud container clusters create influxdb-grafana \
                --num-nodes 1 \
                --machine-type n1-standard-1 \
                --zone $ZONE

# Create the secret
kubectl create secret generic influxdb-grafana \
  --from-literal=influxdb-user=admin \
  --from-literal=influxdb-password=passw0rd \
  --from-literal=grafana-user=admin \
  --from-literal=grafana-password=passw0rd

# Deploy InfluxDB and Grafana to Kubernetes
kubectl create -f k8s/

# See the services external IPs / ports
kubectl get services
