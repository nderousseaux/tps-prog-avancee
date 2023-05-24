# Programmation avancée - Université de Strasbourg (M1) - TPs

This repo contains the correction of pratical works of the Programmation Avancée course.

## Compilation

We use CMake to configure and build the project.
To compile this projet, you might use the following:

```bash
mkdir build
cd build
cmake -S ../ -B ./
cmake --build ./
```

Alternatively, you can use `cmake --build ./ -j8` to enable cmake to use 8 cores for parallel compilation (change 8 to whatever the number of cores you want to use).