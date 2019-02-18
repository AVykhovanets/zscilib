# Zephyr Scientific Library (zscilib)

The **Zephyr scientific library (zscilib)** is an attempt to provide a set of functions
useful for scientific computing, data analysis and data manipulation in the
context of resource constrained embedded devices or 'end nodes'.

### Motivation

Numerous high quality, mature, open source scientific libraries already exist:

- [GNU scientific library (gsl)](https://www.gnu.org/software/gsl/)
- [CMSIS-DSP](http://www.keil.com/pack/doc/CMSIS/DSP/html/index.html)

So, why reinvent the wheel with zscilib?

Despite the wealth of mature functions in these existing libraries, they tend
to have the following problems in an embedded context:

- They are overly broad and resource intensive (in the case of GSL)
- They are missing many of the domain-specific features required to convert
  raw sensor data into actionable information (CMSIS-DAP).

The second item is of particular importance, since the goal of embedded systems
is often 'sensing' via raw data, manipulating that data, then acting on the
converted data points or passing them on for further analysis.

CMSIS-DAP contains a number of highly efficient algorithms for filtering
raw sensor data, but it doesn't offer any domain-specific assistance converting
filtered accelerometer vectors into orientation data, for example, or reading
a set of photodiodes and converting that data into a useful photometric value
like lux.

This library attempts to bridge the divide between raw data, and actionable,
scientifically-relevant data points, in a resource-constrained environment.
It aims to provide helpers for common mathematical operations (linear algebra,
statistical analysis, etc.), as well as domain-specific algorithms in fields
commonly associated with embedded devices.

## Current Features

### Vector Operations

- [x] Add
- [x] Subtract
- [x] Negate
- [x] Sum (two or more vectors)
- [x] Magnitude
- [x] Scalar multiply
- [x] Distance (between two vectors)
- [x] Norm/absolute value
- [x] To Unit Vector
- [x] Dot product
- [x] Cross product
- [x] Sum of squares
- [x] Mean (two or more vectors)
- [x] Equality check

### Matrix Operations

- [x] Add
- [x] Subtract
- [x] Multiply
- [x] Scalar multiply
- [x] Transpose
- [ ] Invert
- [x] Get/set row/column vector
- [ ] Min/max value or index
- [ ] Minor
- [ ] Determinant
- [ ] Cofactor
- [ ] Adjoint
- [ ] Eigenvalues and eigenvectors

## Planned Features

The Zephyr scientific library is still in very early planning, but the
features listed below have been defined as key goals.

> Any suggested additions to this list are highly welcome at this early stage.

### Numerical Analysis

#### Matrix Operations

- Singular value decomposition (SVD)
- Pseudoinverse (AKA Moore-Penrose inverse)

#### Statistics Operations

- Mean
- Median
- Quantile
- Quartile
- Mode
- Data range
- De-mean
- Variance
- Standard deviation
- Interquartile range
- Covariance
- Correlation
- Error

#### Probability Operations

- Uniform probability density function (PDF)
- Uniform cumulative distribution function (CDF)
- Normal probability density function
- Normal cumulative distribution function
- Inverse normal cumulative distribution function
- Information entropy

### Digital Signal Processing

- Simple moving average filter
- Windowed moving average filter
- Weighted moving average filter
- Other basic IIR and FIR-type filters and helper functions.

### Calibration Management

- A framework to persist, retrieve and apply calibration coefficients.

### Domain-Specific Operations

#### Motion and Orientation

- Acceleration/magnetic field -> orientation
- Sensor fusion (accel/mag/gyro -> quaternion)
- Euler/Quaternion conversion
- Functions for acceleration, time/distance, etc.

#### Spectrometry

- Conversion between radiometric and photometric units
- Radiometric data to lux
- Spectral analysis

## Usage

### Adding zscilib to your Zephyr project

**TODO**: Setup Instructions based on `west`.

### Running Unit Tests

To run the unit tests for this library, run the following command:

```
$ sanitycheck -p qemu_cortex_m3 -T ext/lib/zsl/tests/
```

See the `tests` folder for further details.

## Contributing

TODO: Note on how to contribute, and what it most needed at present.

## License

Apache 2.0.
