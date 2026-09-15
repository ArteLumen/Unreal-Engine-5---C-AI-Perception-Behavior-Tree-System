# Unreal Engine 5 - C++ AI Perception & Behavior Tree System

This repository provides a complete, production-ready C++ NPC AI system for Unreal Engine 5. It uses **AI Perception (Sight)** to dynamically track the player and switch between **Patrolling** and **Chasing** behaviors via **Behavior Trees** and **Blackboards**.

---

## 📑 Table of Contents
- [Features](#features)
- [Project Architecture](#project-architecture)
- [Setup & Installation](#setup--installation)
- [C++ Code Breakdown](#c-code-breakdown)
- [License](#license)

---

## ✨ Features
* **Sight Perception:** Detects targets using `UAISenseConfig_Sight`.
* **State Management:** Updates Blackboard keys (`TargetActor`, `HasLineOfSight`) in real-time.
* **Automatic Possession:** Automatically assigns custom `AIController` to spawned or placed NPCs.
* **Behavior Tree Integration:** Clean separation between C++ perception logic and UE Visual AI Nodes.

---

## 🛠️ Setup & Installation

### 1. Engine & NavMesh Setup
1. Drag a **NavMesh Bounds Volume** into your level.
2. Press **P** to confirm the green walkable areas are visible.

### 2. Blackboard Configuration
Create a Blackboard asset (`BB_NPC`) with the following keys:
* `TargetActor` (Type: **Object**, Base Class: **Actor**)
* `HasLineOfSight` (Type: **Bool**)

### 3. Behavior Tree Logic
Structure your **Behavior Tree** graph as follows:
