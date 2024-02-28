
/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

 /****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define SRAM_START  0x20000000U                  /* Inicio da SRAM CORTEX-M */
#define SRAM_SIZE   (128U * 1024U)               /* Tam. SRAM STM32F411 128K */
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE)) /* Final da SRAM STM32F411 */

#define STACK_START SRAM_END                     /* Inicio da Stack */

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

int main(void);

/* Prototipos de funcoes para as System Exceptions */
void Reset_handler(void);
void NMI_handler(void)                  __attribute__((weak, alias("default_handler")));
void HardFault_handler(void)            __attribute__((weak, alias("default_handler")));
void MemManage_handler(void)            __attribute__((weak, alias("default_handler")));
void BusFault_handler(void)             __attribute__((weak, alias("default_handler")));
void UsageFault_handler(void)           __attribute__((weak, alias("default_handler")));
void SVCall_handler(void)               __attribute__((weak, alias("default_handler")));
void DebugMonitor_handler(void)         __attribute__((weak, alias("default_handler")));
void PendSV_handler(void)               __attribute__((weak, alias("default_handler")));
void Systick_handler(void)              __attribute__((weak, alias("default_handler")));
void WWDG_handler(void)                 __attribute__((weak, alias("default_handler")));
void EXTI16_PVD_handler(void)           __attribute__((weak, alias("default_handler")));
void EXTI21_TAMP_STAMP_handler(void)    __attribute__((weak, alias("default_handler")));
void EXTI22_RTC_WKUP_handler(void)      __attribute__((weak, alias("default_handler")));
void FLASH_handler(void)                __attribute__((weak, alias("default_handler")));
void RCC_handler(void)                  __attribute__((weak, alias("default_handler")));
void EXTI0_handler(void)                __attribute__((weak, alias("default_handler")));
void EXTI1_handler(void)                __attribute__((weak, alias("default_handler")));
void EXTI2_handler(void)                __attribute__((weak, alias("default_handler")));
void EXTI3_handler(void)                __attribute__((weak, alias("default_handler")));
void EXTI4_handler(void)                __attribute__((weak, alias("default_handler")));
void DMA1_Stream0_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA1_Stream1_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA1_Stream2_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA1_Stream3_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA1_Stream4_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA1_Stream5_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA1_Stream6_handler(void)         __attribute__((weak, alias("default_handler")));
void ADC_handler(void)                  __attribute__((weak, alias("default_handler")));
void EXTI9_5_handler(void)              __attribute__((weak, alias("default_handler")));
void TIM1_BRK_TIM9_handler(void)        __attribute__((weak, alias("default_handler")));
void TIM1_UP_TIM10_handler(void)        __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_TIM11_handler(void)   __attribute__((weak, alias("default_handler")));
void TIM1_CC_handler(void)              __attribute__((weak, alias("default_handler")));
void TIM2_handler(void)                 __attribute__((weak, alias("default_handler")));
void TIM3_handler(void)                 __attribute__((weak, alias("default_handler")));
void TIM4_handler(void)                 __attribute__((weak, alias("default_handler")));
void I2C1_EV_handler(void)              __attribute__((weak, alias("default_handler")));
void I2C1_ER_handler(void)              __attribute__((weak, alias("default_handler")));
void I2C2_EV_handler(void)              __attribute__((weak, alias("default_handler")));
void I2C2_ER_handler(void)              __attribute__((weak, alias("default_handler")));
void SPI1_handler(void)                 __attribute__((weak, alias("default_handler")));
void SPI2_handler(void)                 __attribute__((weak, alias("default_handler")));
void USART1_handler(void)               __attribute__((weak, alias("default_handler")));
void USART2_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI15_10_handler(void)            __attribute__((weak, alias("default_handler")));
void EXTI17_RTC_Alarm_handler(void)     __attribute__((weak, alias("default_handler")));
void EXTI18_OTG_FS_WKUP_handler(void)   __attribute__((weak, alias("default_handler")));
void DMA1_Stream7_handler(void)         __attribute__((weak, alias("default_handler")));
void SDIO_handler(void)                 __attribute__((weak, alias("default_handler")));
void TIM5_handler(void)                 __attribute__((weak, alias("default_handler")));
void SPI3_handler(void)                 __attribute__((weak, alias("default_handler")));
void DMA2_Stream0_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA2_Stream1_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA2_Stream2_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA2_Stream3_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA2_Stream4_handler(void)         __attribute__((weak, alias("default_handler")));
void OTG_FS_handler(void)               __attribute__((weak, alias("default_handler")));
void DMA2_Stream5_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA2_Stream6_handler(void)         __attribute__((weak, alias("default_handler")));
void DMA2_Stream7_handler(void)         __attribute__((weak, alias("default_handler")));
void USART6_handler(void)               __attribute__((weak, alias("default_handler")));
void I2C3_EV_handler(void)              __attribute__((weak, alias("default_handler")));
void I2C3_ER_handler(void)              __attribute__((weak, alias("default_handler")));
void FPU_handler(void)                  __attribute__((weak, alias("default_handler")));
void SPI4_handler(void)                 __attribute__((weak, alias("default_handler")));
void SPI5_handler(void)                 __attribute__((weak, alias("default_handler")));


/* Variaveis exportadas pelo linker script */

extern uint32_t _sdata;     /* Inicio da secao .data */
extern uint32_t _edata;     /* Fim da secao .data */
extern uint32_t _la_data;   /* Origem da secao .data na FLASH */

extern uint32_t _sbss;      /* Inicio da secao .bss */
extern uint32_t _ebss;      /* Fim da secao .bss */

/* Tabela de Vetores de Interrupção */
uint32_t vectors[] __attribute__((section(".isr_vectors"))) =
{
  STACK_START,                            /* 0x0000 0000 */
  (uint32_t) Reset_handler,               /* 0x0000 0004 */
  (uint32_t) NMI_handler,                 /* 0x0000 0008 */
  (uint32_t) HardFault_handler,           /* 0x0000 000c */
  (uint32_t) MemManage_handler,           /* 0x0000 0010 */
  (uint32_t) BusFault_handler,            /* 0x0000 0014 */
  (uint32_t) UsageFault_handler,          /* 0x0000 0018 */
  0,                                      /* 0x0000 001c */
  0,                                      /* 0x0000 0020 */
  0,                                      /* 0x0000 0024 */
  0,                                      /* 0x0000 0028 */
  (uint32_t) SVCall_handler,              /* 0x0000 002c */
  (uint32_t) DebugMonitor_handler,        /* 0x0000 0030 */
  0,                                      /* 0x0000 0034 */
  (uint32_t) PendSV_handler,              /* 0x0000 0038 */
  (uint32_t) Systick_handler,             /* 0x0000 003c */
  (uint32_t) WWDG_handler,                /* 0x0000 0040 */
  (uint32_t) EXTI16_PVD_handler,          /* 0x0000 0044 */
  (uint32_t) EXTI21_TAMP_STAMP_handler,   /* 0x0000 0048 */
  (uint32_t) EXTI22_RTC_WKUP_handler,     /* 0x0000 004C */
  (uint32_t) FLASH_handler,               /* 0x0000 0050 */
  (uint32_t) RCC_handler,                 /* 0x0000 0054 */
  (uint32_t) EXTI0_handler,               /* 0x0000 0058 */
  (uint32_t) EXTI1_handler,               /* 0x0000 005C */
  (uint32_t) EXTI2_handler,               /* 0x0000 0060 */
  (uint32_t) EXTI3_handler,               /* 0x0000 0064 */
  (uint32_t) EXTI4_handler,               /* 0x0000 0068 */
  (uint32_t) DMA1_Stream0_handler,        /* 0x0000 006C */
  (uint32_t) DMA1_Stream1_handler,        /* 0x0000 0070 */
  (uint32_t) DMA1_Stream2_handler,        /* 0x0000 0074 */
  (uint32_t) DMA1_Stream3_handler,        /* 0x0000 0078 */
  (uint32_t) DMA1_Stream4_handler,        /* 0x0000 007C */
  (uint32_t) DMA1_Stream5_handler,        /* 0x0000 0080 */
  (uint32_t) DMA1_Stream6_handler,        /* 0x0000 0084 */
  (uint32_t) ADC_handler,                 /* 0x0000 0088 */
  (uint32_t) EXTI9_5_handler,             /* 0x0000 009C */
  (uint32_t) TIM1_BRK_TIM9_handler,       /* 0x0000 00A0 */
  (uint32_t) TIM1_UP_TIM10_handler,       /* 0x0000 00A4 */
  (uint32_t) TIM1_TRG_COM_TIM11_handler,  /* 0x0000 00A8 */
  (uint32_t) TIM1_CC_handler,             /* 0x0000 00AC */
  (uint32_t) TIM2_handler,                /* 0x0000 00B0 */
  (uint32_t) TIM3_handler,                /* 0x0000 00B4 */
  (uint32_t) TIM4_handler,                /* 0x0000 00B8 */
  (uint32_t) I2C1_EV_handler,             /* 0x0000 00BC */
  (uint32_t) I2C1_ER_handler,             /* 0x0000 00C0 */
  (uint32_t) I2C2_EV_handler,             /* 0x0000 00C4 */
  (uint32_t) I2C2_ER_handler,             /* 0x0000 00C8 */
  (uint32_t) SPI1_handler,                /* 0x0000 00CC */
  (uint32_t) SPI2_handler,                /* 0x0000 00D0 */
  (uint32_t) USART1_handler,              /* 0x0000 00D4 */
  (uint32_t) USART2_handler,              /* 0x0000 00D8 */
  (uint32_t) EXTI15_10_handler,           /* 0x0000 00E0 */
  (uint32_t) EXTI17_RTC_Alarm_handler,    /* 0x0000 00E4 */
  (uint32_t) EXTI18_OTG_FS_WKUP_handler,  /* 0x0000 00E8 */
  (uint32_t) DMA1_Stream7_handler,        /* 0x0000 00FC */
  (uint32_t) SDIO_handler,                /* 0x0000 0104 */
  (uint32_t) TIM5_handler,                /* 0x0000 0108 */
  (uint32_t) SPI3_handler,                /* 0x0000 010C */
  (uint32_t) DMA2_Stream0_handler,        /* 0x0000 0120 */
  (uint32_t) DMA2_Stream1_handler,        /* 0x0000 0124 */
  (uint32_t) DMA2_Stream2_handler,        /* 0x0000 0128 */
  (uint32_t) DMA2_Stream3_handler,        /* 0x0000 012C */
  (uint32_t) DMA2_Stream4_handler,        /* 0x0000 0130 */
  (uint32_t) OTG_FS_handler,              /* 0x0000 014C */
  (uint32_t) DMA2_Stream5_handler,        /* 0x0000 0150 */
  (uint32_t) DMA2_Stream6_handler,        /* 0x0000 0154 */
  (uint32_t) DMA2_Stream7_handler,        /* 0x0000 0158 */
  (uint32_t) USART6_handler,              /* 0x0000 015C */
  (uint32_t) I2C3_EV_handler,             /* 0x0000 0160 */
  (uint32_t) I2C3_ER_handler,             /* 0x0000 0164 */
  (uint32_t) FPU_handler,                 /* 0x0000 0184 */
  (uint32_t) SPI4_handler,                /* 0x0000 0190 */
  (uint32_t) SPI5_handler                 /* 0x0000 0194 */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

void reset_handler(void)
{
  uint32_t i; 

  /* Copia a secao .data para a RAM */
  uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *pDst = (uint8_t*)&_sdata;                      /* SRAM */
  uint8_t *pSrc = (uint8_t*)&_la_data;                    /* FLASH */
  
  for(i = 0; i < size; i++)
  {
    *pDst++ = *pSrc++;
  }

  /* Preenche a secao .bss com zero */
  size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  pDst = (uint8_t*)&_sbss;
  for(i = 0 ; i < size; i++)
  {
    *pDst++ = 0;
  }

  /* Chama a funcao main() */
  main();
}

void default_handler(void)
{
  while(1){};
}
