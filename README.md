# CPP Module 06

This module focuses on **C++ type casting** and how data can be converted safely between different types.

---

##  Overview

In this project, we explore:

* Scalar type conversion
* Pointer serialization
* Runtime type identification (RTTI)

---

##  What I Learned

* How to convert between `char`, `int`, `float`, and `double`
* Difference between:

  * `static_cast`
  * `reinterpret_cast`
  * `dynamic_cast`
* How pointers can be represented as integers
* How to detect the real type of an object at runtime

---

##  Exercises

###  ex00 — Scalar Conversion

Convert a string literal into:

* `char`
* `int`
* `float`
* `double`

Example:

```bash
./convert 42
```

Output:

```text
char: '*'
int: 42
float: 42.0f
double: 42.0
```

Concepts used:

* Parsing input
* Type conversion
* Handling edge cases (`nan`, `inf`, invalid input)

---

### 🔹 ex01 — Serialization

Convert a pointer into an integer and back:

```cpp
uintptr_t raw = Serializer::serialize(ptr);
Data* restored = Serializer::deserialize(raw);
```

Concepts used:

* `reinterpret_cast`
* Pointer ↔ Integer conversion
* Memory representation

---

###  ex02 — Identify Real Type

Generate a random object (`A`, `B`, or `C`) and identify its real type.

```cpp
Base* obj = generate();
identify(obj);
identify(*obj);
```

Concepts used:

* Inheritance
* Polymorphism
* `dynamic_cast`
* Runtime Type Identification (RTTI)

---

##  How to Compile & Run

Each exercise has its own Makefile.

Example:

```bash
cd ex00
make
./convert 42
```

---

##  Key Concepts

### `static_cast`

Used for safe and known conversions at compile time.

### `reinterpret_cast`

Used for low-level conversions (e.g., pointer ↔ integer).

### `dynamic_cast`

Used to safely check the real type of objects at runtime.

---

##  Conclusion

This module helped me understand how C++ handles:

* Type safety
* Memory representation
* Runtime type checking

