import base64
import json
from datetime import datetime

from influxdb import InfluxDBClient

def iotcore_pubsub_to_influxdb(data, context):
    if data['data'] is None or data['attributes'] is None or data['attributes']['deviceId'] is None:
        print('Invalid data received: {}'.format(data))
        return

    influxdb_client = _get_influxdb_client()
    device_id = data['attributes']['deviceId']
    json_data = base64.b64decode(data['data']).decode('utf-8')
    iot_data = json.loads(json_data)
    time_str = str(iot_data['timestamp'])
    measurement = "illuminance"
    value = iot_data['points']['illuminance_sensor']['present_value']
    print(device_id, time_str, measurement, value)
    _send_sensor_data_to_influxdb(influxdb_client, device_id, time_str, measurement, value)

def _get_influxdb_client():
    host = '34.78.220.235'
    port = 8086
    username = 'admin'
    password = 'passw0rd'
    database = 'iot'
    return InfluxDBClient(host, port, username, password, database)

def _send_sensor_data_to_influxdb(client, device_id, time_str, measurement, value):
    json_body = [
        {
            'measurement': measurement,
            'tags': {
                'device': device_id
            },
            'time': time_str,
            'fields': {
                'value': float(value)
            }
        }
    ]
    client.write_points(json_body)
