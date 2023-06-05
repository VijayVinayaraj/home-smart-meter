#ifndef mesh_H
#define mesh_H

#include "esp_wifi.h"
#include <string.h>
#include "esp_wifi.h"
#include "esp_mac.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_mesh.h"
#include "esp_mesh_internal.h"
#include "nvs_flash.h"



#define HOSTPORT 3000


#define CONFIG_MESH_CHANNEL 10
#define CONFIG_MESH_TOPOLOGY  MESH_TOPO_TREE
#define CONFIG_MESH_MAX_LAYER  5
#define CONFIG_MESH_ROUTER_SSID "wifi"
#define CONFIG_MESH_ROUTER_PASSWD "1234567890"
#define CONFIG_MESH_AP_AUTHMODE WIFI_AUTH_WPA2_PSK
#define CONFIG_MESH_AP_CONNECTIONS 6
#define CONFIG_MESH_AP_PASSWD "123456789"

#define RX_SIZE          (1500)
#define TX_SIZE          (1460)

void mesh_init();
#endif