#!/bin/bash

PROJECT_ID=iot-workshop-2020

openssl ecparam -genkey -name prime256v1 -noout -out "$PROJECT_ID"_ec_private.pem
openssl ec -in "$PROJECT_ID"_ec_private.pem -pubout -out "$PROJECT_ID"_ec_public.pem

