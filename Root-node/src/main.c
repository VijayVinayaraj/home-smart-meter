
#include "main.h"
// static const char TAG[]="main";

QueueHandle_t energyQueue;
SemaphoreHandle_t data = NULL;

void getEnergyData()
{
    uint16_t energy = getEnergy();
    uint32_t accumulatedEnergy = accumulatedEnergy + energy;

    uint32_t checkData;

    if (xQueuePeek(energyQueue, (void *)&checkData, 0) == pdTRUE)
    {
        xQueueSend(energyQueue, &accumulatedEnergy, portMAX_DELAY);
        xSemaphoreGive(data);
    }
}

void sendEnergyToMqttBroker()
{
    uint32_t energyData = 0;

    if (xSemaphoreTake(data))
    {

        if (xQueueReceive(energyQueue, &energyData, portMAX_DELAY))
        {
            
        }
    }
}

void app_main()
{

    // initialize the spi interface
    spi_init();
    // calibrate the m90e26 with gain values
    calibrateIC();
    // initialize and connect the mesh connection
    mesh_init();
    // initialize  the mqtt client give broker address mqtt.h
    mqttInit();
    // initialize the ntp server for time
    initialize_sntp(void);

    energyQueue = xQueueCreate(10, sizeof(uint32_t));
    data = xSemaphoreCreateBinary();
}
