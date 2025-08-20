# 🍝 Philosophers — Dining Philosophers Simulator

> A multithreaded concurrency project simulating the dining philosophers problem.  
> Built in C with `pthread`, focusing on synchronization, timing, and deadlock prevention.

---

### 📜 Project Overview

**Philosophers** is a CLI program written in C that simulates philosophers sitting at a table, alternating between eating, thinking, and sleeping.  
Each philosopher needs two forks (mutexes) to eat, and the program ensures **no deadlocks** and **fair access** to resources.  
It’s a deep dive into multithreading, synchronization, and precise time handling.

---

### ⚙️ Features

- 🧵 **Threaded philosophers** using `pthread_create`
- 🍴 **Mutex-protected forks** to avoid race conditions
- ⏱️ **Precise action timing** (`time_to_die`, `time_to_eat`, `time_to_sleep`)
- ⚰️ **Death detection** if a philosopher misses meals
- ✅ Optional limit: stop after each philosopher eats `N` times
- 🎨 **Colored terminal messages** for better readability
- 🧼 **Graceful cleanup** of memory and mutexes

---

## 🛠️ Technologies Used

- Language: **C**
- Libraries: `pthread`, `unistd`, `stdlib`, `sys/time`
- Synchronization: POSIX **mutexes**
- Timing: `gettimeofday`

---

### 📦 Build & Run Instructions

#### 🧰 Requirements
- GCC compiler
- POSIX Threads (`pthread`)

### 🔨 Build
```bash
make
```
### 🚀 Run
```bash
./philo [Amount of Philos] [Time Before Death] [Time to Eat] [Time to Sleep] ([Amount of Meals])
```

Example:
```bash
./philo 5 800 200 200 50
```
<sub>No Die</sub>

---

### 🔀 Flowchart
<img width="1290" height="2560" alt="image" src="https://github.com/user-attachments/assets/04608fa4-62e1-484d-8e7b-31bef9c1cdcc" />

> Feel free to drop a star! ⭐️
