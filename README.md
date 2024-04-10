# Dynacoustic

This design prototype delves into the art of dynamic indoor acoustics, highlighting its capacity to elevate human experiences. It contrasts conventional static acoustic treatment approaches, advocating for adaptive, additive, and automated treatments that adapt to varying activities.

The interactive acoustic panel prototype exemplifies these principles. Users can manipulate sound absorption, integrate artificial reverb, and trigger automated adjustments based on factors such as time, light, and ambient sound levels.

The prototype underscores the possibilities of dynamic acoustics in a noise-focused world, prompting contemplation on its potential to enhance human engagement within indoor environments instead of muting its auditory characteristics.

The key to the acoustic panel's versatility lies in its ten rotatable prisms, which can alter the panel's surface from sound-absorbing to sound-reflecting. Each prism is mounted with ball bearings at both ends to reduce sound and friction resistance during rotation. At the top of each prism is a gear, rotated at a ratio of 1:6 by a smaller gear attached to the shaft of a linear DC motor. All these motors are connected and controlled by an Arduino Uno single-board microcontroller.

Connected to this microcontroller are a potentiometer, three push buttons, and six indicator LEDs, forming the user interface of the prototype. From here, users can select acoustic modes, adjust the amount of sound absorption, control artificial reverberation, or activate one of the three automatic acoustic parameters. Additionally, the microcontroller receives input from a light-dependent resistor and a sound sensor module, regulating light and sound parameters when using the automatic mode.

Outside the microcontroller circuitry, the panel houses a digital reverb effect. When the additive mode is activated, the prisms are turned to become sound-absorbing, minimizing the room's original reverberation. The digital reverb adds to an incoming audio signal from an external microphone, played through a speaker on the side of the acoustic panel. This setup in the artifact associated with this task represents a technological compromise resulting from various challenges encountered during the construction process, reflecting accumulated designer experiences and knowledge, which will be further discussed later in this section.

It's important to note that due to its size, the artifact presented here has limitations in effectively altering room acoustics. Thus, it serves primarily as an exploratory prototype of a vision and represents only a component of the overall vision for the work.

[See a demonstration of the prototype in use here.](https://www.thomaseg.dk/)

## Design prototype
![Design prototype](images/overview.png)

## Levels of acoustic absorption
![Acoustic modes](images/modes.png)

## Interface
![User interface](images/interface.png)

## Motors and electronic circuit
![Circuit](images/circuit.png)
