![Static Badge](https://img.shields.io/badge/Unic_Lab-green)
![Static Badge](https://img.shields.io/badge/STM32-red)
![GitHub last commit (by committer)](https://img.shields.io/github/last-commit/Vernicovskiy/STM32_TIM)
![GitHub Repo stars](https://img.shields.io/github/stars/Vernicovskiy/STM32_TIM)
![GitHub watchers](https://img.shields.io/github/watchers/Vernicovskiy/STM32_TIM)
![GitHub top language](https://img.shields.io/github/languages/top/Vernicovskiy/STM32_TIM)

# Изучение явления дребезга контактов и анализ временных параметров сигналов клавиш
* NUCLEO-F401RE
 * STM32F401RET6U
 * ARM Cortex M4
 * CMSIS
 * STM32 CubeIDE v1.13.2

> В данном проекте зайдействована пользовательская кнопка B1, подключенная к порту PC13 по обратной логике.

<p align="center">
 <img src="PNG/image.png" alt="Diagram of System Timer (SysTick)" width="200"/>
<p align="center">

## Конфигурация порта микрокнтроллера на вход 

<p align="center">
 <img src="PNG/image-1.png" alt="Diagram of System Timer (SysTick)" width="500"/>
<p align="center">

Порт микроконтроллера может находится в трех состояниях: __высоком__, __низком__ и в состоянии __HiZ__ (высокоимпедансном)

## Принцип работы Триггера Шмитта 
<p align="center">
 <img src="PNG/image-3.png" alt="Diagram of System Timer (SysTick)" width="500"/>
 <p align="center">

## Явление дребезга контактов 
Дребезг представляет собой многократное замыкание и размыкание цепи. В результате на вход микропроцессорного устройства поступает не единичный перепад напряжения, а целая пачка импульсов. Примерная форма сигнала на таких контактах в момент замыкания показана на рисунке. 
<p align="center">
 <img src="PNG/image-4.png" alt="Diagram of System Timer (SysTick)" width="300"/>
<p align="center">

 Методы борьбы:
* Аппаратные 
    * RC-цепочки
    * Антидребезговые микросхемы 
* Программные
    * Программная задержка 





