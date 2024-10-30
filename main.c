#include "contiki.h"
#include <stdio.h>
#include <stdlib.h>

// Declaração dos processos para monitoramento dos dados vitais
PROCESS(heart_rate_monitor_process, "Monitoramento de Batimentos Cardíacos");
PROCESS(oxygen_saturation_monitor_process, "Monitoramento de Saturação de Oxigênio");
PROCESS(temperature_monitor_process, "Monitoramento de Temperatura Corporal");
PROCESS(alert_monitor_process, "Monitoramento de Alertas");

// Inicializa os processos ao iniciar o sistema
AUTOSTART_PROCESSES(&heart_rate_monitor_process, &oxygen_saturation_monitor_process, &temperature_monitor_process, &alert_monitor_process);

// Variáveis globais para armazenamento dos dados vitais
static int heart_rate = 0;
static int oxygen_saturation = 0;
static int temperature = 0;
static process_event_t alert_event;

// Processo para monitoramento de batimentos cardíacos
PROCESS_THREAD(heart_rate_monitor_process, ev, data)
{
    PROCESS_BEGIN();

    while(1) {
        // Gera valor randômico entre 20 e 140 para simular batimentos cardíacos
        heart_rate = 20 + (rand() % 121);
        printf("Batimentos Cardíacos: %d bpm\n", heart_rate);

        // Verifica se o batimento está fora do intervalo normal e gera evento de alerta
        if (heart_rate < 50) {
            printf("ALERTA: Batimento cardíaco baixo!\n");
            process_post(&alert_monitor_process, alert_event, "Batimento cardíaco baixo");
        } else if (heart_rate > 90) {
            printf("ALERTA: Batimento cardíaco alto!\n");
            process_post(&alert_monitor_process, alert_event, "Batimento cardíaco alto");
        }

        // Espera 3 segundos antes da próxima leitura
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
        etimer_reset(&et);
    }

    PROCESS_END();
}

// Processo para monitoramento de saturação de oxigênio
PROCESS_THREAD(oxygen_saturation_monitor_process, ev, data)
{
    PROCESS_BEGIN();

    static struct etimer et;
    etimer_set(&et, CLOCK_SECOND * 3);

    while(1) {
        // Gera valor randômico entre 80 e 100 para simular saturação de oxigênio
        oxygen_saturation = 80 + (rand() % 21);
        printf("Saturação de Oxigênio: %d%%\n", oxygen_saturation);

        // Verifica se a saturação está fora do intervalo normal e gera evento de alerta
        if (oxygen_saturation < 90) {
            printf("ALERTA: Saturação de oxigênio baixa!\n");
            process_post(&alert_monitor_process, alert_event, "Saturação de oxigênio baixa");
        }

        // Espera 3 segundos antes da próxima leitura
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
        etimer_reset(&et);
    }

    PROCESS_END();
}

// Processo para monitoramento de temperatura
PROCESS_THREAD(temperature_monitor_process, ev, data)
{
    PROCESS_BEGIN();

    static struct etimer et;
    etimer_set(&et, CLOCK_SECOND * 3);

    while(1) {
        // Gera valor randômico entre 34 e 41 para simular temperatura corporal
        temperature = 34 + (rand() % 8);
        printf("Temperatura Corporal: %d°C\n", temperature);

        // Verifica se a temperatura está fora do intervalo normal e gera evento de alerta
        if (temperature < 35) {
            printf("ALERTA: Hipotermia!\n");
            process_post(&alert_monitor_process, alert_event, "Hipotermia");
        } else if (temperature > 37) {
            printf("ALERTA: Febre!\n");
            process_post(&alert_monitor_process, alert_event, "Febre");
        }

        // Espera 3 segundos antes da próxima leitura
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
        etimer_reset(&et);
    }

    PROCESS_END();
}

// Processo para monitoramento de alertas
PROCESS_THREAD(alert_monitor_process, ev, data)
{
    PROCESS_BEGIN();

    while(1) {
        // Aguarda um evento de alerta de qualquer processo de monitoramento
        PROCESS_WAIT_EVENT_UNTIL(ev == alert_event);

        // Imprime a mensagem de alerta recebida
        printf("ALERTA: %s\n", (char *)data);
    }

    PROCESS_END();
}



