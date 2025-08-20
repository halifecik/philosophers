# 🍝 Philosophers — Dining Philosophers Problem

> A multithreaded solution to the classic dining philosophers problem.  
> Written in C as part of the 42 curriculum, this project demonstrates safe concurrency, synchronization, and deadlock prevention.

---

## 📜 Project Overview

**Philosophers** simulates a group of philosophers sitting around a table, alternating between eating, thinking, and sleeping.  
Forks are shared resources, and philosophers must pick up two forks (mutexes) to eat.  
The challenge: prevent **deadlocks** and ensure no philosopher starves while handling **precise timing**.

This implementation is modular, with clear separation of concerns:
- Argument parsing and validation
- Initialization of data structures and mutexes
- Philosopher lifecycle (threads)
- Monitoring for death/starvation
- Resource cleanup

---

## ⚙️ Features

- 🧵 **Threaded philosophers** using `pthread_create`
- 🍴 **Fork management** with mutexes
- ⏱️ **Precise action timing** (`time_to_die`, `time_to_eat`, `time_to_sleep`)
- ⚰️ **Death detection** if a philosopher doesn’t eat within `time_to_die`
- ✅ Optional argument: `number_of_times_each_philosopher_must_eat`
- 🎨 **Colored terminal messages** for better visualization
- 🧼 **Full cleanup** of mutexes and memory after simulation

---

## 🛠️ Technologies Used

- Language: **C**
- Libraries: `pthread`, `unistd`, `stdio`, `stdlib`, `sys/time`
- Synchronization: **POSIX mutexes**
- Time tracking: `gettimeofday`

---

## 📦 Build & Run Instructions

### 🧰 Build
```bash
make
```

Run
```bash
./philo [Amoun of Philos] [Time Before Death] [Time to Eat] [Time to Sleep] ([Amount of Meals])
```
Example >No-Die
```bash
./philo 5 800 200 200 [Optional]
```

## 🔀 Flowchart
<img width="1290" height="2560" alt="image" src="https://github.com/user-attachments/assets/04608fa4-62e1-484d-8e7b-31bef9c1cdcc" />
> Feel free to drop a star! ⭐️
