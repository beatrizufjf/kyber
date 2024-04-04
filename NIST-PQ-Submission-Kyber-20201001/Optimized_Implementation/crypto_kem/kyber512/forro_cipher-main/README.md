# Forró

This repository contains the implementation for the Forró cipher, a fast stream cipher proposed at [Asiacrypt 2022](https://link.springer.com/chapter/10.1007/978-3-031-22963-3_9).

To build the reference code and it's test just run:

```
make
```

or

```
make test_ref
```

To build only the reference code:

```
make ref
```

Similarly, `x86_simd` and `test_x86_simd` are targets for the x86 with AVX2, and `neon` and `test_neon` for ARM Neon.

The tests can be run with:

```
./build/test_ref
```

or it's respective.
