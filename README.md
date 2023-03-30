<a id="library"></a>

# gbj\_appbase
This is an application library, which is used usually as a project library for particular PlatformIO project. It provides common core methods for project centric application libraries **with internal timer** and acts as their parent class with following advantages:

* It utilizes funcionality from the parent class.
* The library is reusable for various projects providing basic functionality.
* Update in library is valid for all involved projects.


## Fundamental functionality

* The library specifies (inherits from) the parent application library `gbj_appcore` and extends it with virtual methods for managing internal timers, which every child class should implement.
* A child class should created an internal timer. If it is not needed, use rathe the _gbj\_appcore_ library as a parent class.
* It provides error handling for all derived classes.


<a id="dependency"></a>

## Dependency
* **gbj\_appcore**: Parent library loaded from the file `gbj_appcore.h`.

#### Arduino platform
* **Arduino.h**: Main include file for the Arduino SDK.
* **inttypes.h**: Integer type conversions. This header file includes the exact-width integer definitions and extends them with additional facilities provided by the implementation.

#### Espressif ESP8266 platform
* **Arduino.h**: Main include file for the Arduino platform.

#### Espressif ESP32 platform
* **Arduino.h**: Main include file for the Arduino platform.

#### Particle platform
* **Particle.h**: Includes alternative (C++) data type definitions.


<a id="interface"></a>

## Interface
It consists only from virtual methods:

* [run()](#run)
* [setPeriod()](#setPeriod)
* [getPeriod()](#getPeriod)

## run()

#### Description
The execution method, which should be called frequently, usually in the loop function of a main sketch.

#### Syntax
	virtual void run()

#### Parameters
None

#### Returns
None

[Back to interface](#interface)


<a id="setPeriod"></a>

## setPeriod()

#### Description
The method sets a new period of the internal timer in milliseconds.
The overloaded method sets a new period of the internal timer in milliseconds input either in milliseconds or in seconds.
* The numerical argument is considered in milliseconds.
* The textual argument is considered in seconds. It is useful with conjunction with a project data hub, which data has always string data type.

#### Syntax
    virtual void setPeriod(unsigned long period)
    virtual void setPeriod(String periodSec)

#### Parameters
* **period**: Duration of a repeating interval of the internal timer in milliseconds declared as integer.
  * *Valid values*: 0 ~ 2^32 - 1
  * *Default value*: none


* **periodSec**: Duration of a repeating interval of the internal timer in seconds declared as string.
  * *Valid values*: String
  * *Default value*: none

#### Returns
None

#### See also
[getPeriod()](#getPeriod)

[Back to interface](#interface)


<a id="getPeriod"></a>

## getPeriod()

#### Description
The method returns current period of the internal timer.

#### Syntax
    virtual unsigned long getPeriod()

#### Parameters
None

#### Returns
Current timer period in milliseconds.

#### See also
[setPeriod()](#setPeriod)

[Back to interface](#interface)
