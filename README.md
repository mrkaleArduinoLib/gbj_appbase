<a id="library"></a>

# gbj\_appbase
This is an application library, which is used usually as a project library for particular PlatformIO project. It provides common core methods for project centric application libraries **with internal timer **and acts as their parent class.

- Library just extends its parent class with virtual methods, that should every derived class implement.
- Library utilizes error handling from the parent class.


<a id="dependency"></a>

## Dependency
- **gbj\_appcore**: Parent library loaded from the file `gbj_appcore.h`.

#### Arduino platform
- **Arduino.h**: Main include file for the Arduino SDK.
- **inttypes.h**: Integer type conversions. This header file includes the exact-width integer definitions and extends them with additional facilities provided by the implementation.

#### Espressif ESP8266 platform
- **Arduino.h**: Main include file for the Arduino platform.

#### Espressif ESP32 platform
- **Arduino.h**: Main include file for the Arduino platform.

#### Particle platform
- **Particle.h**: Includes alternative (C++) data type definitions.


<a id="constants"></a>

## Constants

- **gbj\_appbase::VERSION**: Name and semantic version of the library.

Other constants, enumerations, result codes, and error codes are inherited from the parent library.


<a id="interface"></a>

## Interface
It consists only from virtual methods:

- [run()](#run)
- [setPeriod()](#setPeriod)
- [getPeriod()](#getPeriod)

## run()

#### Description
The execution method, which should be called frequently, usually in the loop function of a sketch.

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
The method sets a new period of the internal timer.

#### Syntax
    virtual void setPeriod(unsigned long period)

#### Parameters
- **period**: Duration of a repeating interval in milliseconds.
  - *Valid values*: 0 ~ 2^32 - 1
  - *Default value*: none

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
[setPeriod()](#getPeriod)

[Back to interface](#interface)
