#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <nvs.h>
#include "nvs_flash.h"


int32_t acessVal_NVS();
void writeVal_NVS(int32_t valor);




void setup() 
{

  Serial.begin(9600);

  
}

void loop() 
{

  int32_t valor_lido = 0;

  valor_lido = acessVal_NVS();

  if (valor_lido == -1)
  {
    valor_lido = 0;
  }

  writeVal_NVS(valor_lido);

  delay(10000);

}



int32_t acessVal_NVS()
{

    nvs_handle particao_padrao_handle;
    int32_t valor = 0;
    
    ESP_ERROR_CHECK(nvs_flash_init());

    esp_err_t res_nvs = nvs_open("armazenamento", NVS_READONLY, &particao_padrao_handle);

    if (res_nvs == ESP_ERR_NVS_NOT_FOUND)
    {
      Serial.printf("NVS, Namespace: armazenamento, não encontrado");

    }
    else
    {
      esp_err_t res = nvs_get_i32(particao_padrao_handle, "contador", &valor);

      switch (res)
      {
      case ESP_OK:
        Serial.printf("Valor Armazenado:  %d \n", valor);
        break;

      case ESP_ERR_NOT_FOUND:
        Serial.printf("NVS: Valor não encontrado");

      default:
        Serial.printf("NVS: Erro ao acessar o NVS (%s)", esp_err_to_name(res));
        return -1;
        break;
      }

      nvs_close(particao_padrao_handle);
    }

    return valor;
}


void writeVal_NVS(int32_t valor)
{

  ESP_ERROR_CHECK(nvs_flash_init());

  nvs_handle particao_padrao_handle;

  esp_err_t res_nvs = nvs_open("armazenamento", NVS_READWRITE, &particao_padrao_handle);
  
  if (res_nvs == ESP_ERR_NVS_NOT_FOUND)
  {
    Serial.printf("NVS: Namespace: armazenamento, não encontrado");
  }

  Serial.printf("%d", valor);
  esp_err_t res = nvs_set_i32(particao_padrao_handle,"contador", valor + 5);
  
  if(res != ESP_OK)
  {
    Serial.printf("NVS: Não foi possível escrever no NVS (%s)", esp_err_to_name(res));
  }

  nvs_commit(particao_padrao_handle);
  nvs_close(particao_padrao_handle);

}
