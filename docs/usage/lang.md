# Table of contents

* [RLCLang](#rlclang)
	* [What and why?](#what-and-why)
* [Language features](#language-features)
	* [Comments](#comments)
	* [Declarations](#declarations)
* [How to use](#how-to-use)

# RLCLang

## What and why?

RLCLang was made as a language to act as a Resource file for Windows.

The reason why it was made is for use on any platform as it just compiles to a C header file.

# Language features

Currently, the language does not support much, but here's what it does support:

* [Comments](#comments)
* [Declarations](#declarations)

Yea, it's not much.

So how do you use it?

## Comments

RLCLang supports C-style comments,
but currently no multi-line comments are supported.

The syntax goes like this

```c
// This is a comment
/* But this is unimplemented. */
```

## Declarations

A declaration is made using the "var" keyword

The "var" keyword is used like the following

```rlc
var foo = 42;
```

Breaking this down, a declaration is being made for "foo" and is getting the value of 42.

Remember that semicolons are required, but the compiler currently can't handle multi-line statements, so you can't have anything like this:

```rlc
var
foo = 42;
```

# How to use

Now for an example, lets say you have this source code:

```rlc
var foo = 42;
var bar = 21;
```

Now how could we use `foo`, `bar`, or `baz` in some code?

Let's say we have this:

```c
#include<stdio.h>

int main() {
	// Should print the sum of foo and bar
	printf("foo + bar = %d\n", 63);
	return 0;
}
```

But this code is not correct because it's just hardcoding the value.

Lets take a look at what the compiler gives.

```c
// This file was compiled by the KRC-TP.
#ifndef foo
#define foo 42
#endif
#ifndef bar
#define bar 21
#endif
```

As you can see, what it does is put the variables into C macros.

From this information, all you need to do it use the macros generated.

Now lets say the compiled output was in "example.h"
Then all that would be needed is this:

```c
#include<stdio.h>
#include"example.h"

int main() {
	// Should print the sum of foo and bar
	printf("foo + bar = %d\n", foo + bar);
	return 0;
}
```

And this should print a value of 63.