# U-Turn: Traffic Management System 🚗🚦

**U-Turn** is a comprehensive **Traffic Management System** built in **C** that leverages advanced data structures, algorithms, and file management techniques. It provides a dynamic solution for traffic control and monitoring, including features for managing traffic signals, incidents, violations, emergency vehicle requests, VIP requests, and more.

This project uses **Dijkstra’s Algorithm** for **shortest path calculation**, has **role-based user authentication** (for Admin and Police), and incorporates an **interactive color-coded command-line interface (CLI)** for a better user experience.

## 🚀 Key Features

### 1. **Real-Time Traffic Management**
   - **Traffic Signals Control**: Manage and control traffic signals at different intersections.
   - **Traffic Violation Records**: Register and manage traffic violations, including adding or removing violations.
   - **Incident Management**: Add, remove, and view traffic accidents or incidents.
   - **Emergency Vehicle Handling**: Prioritize emergency vehicles by optimizing traffic flow.
   
### 2. **Shortest Path Calculation (Using Dijkstra's Algorithm)**
   - **Shortest Path Between Cities**: Calculates the shortest route between cities for better traffic management.
   - **Dynamic City Connections**: Add or remove cities and their connections dynamically.

### 3. **User Authentication & Role-Based Access**
   - **Admin Login**: The admin can control signals, incidents, violations, and manage records.
   - **Police Login**: Police can manage emergency requests, traffic violations, accidents, and vehicle registrations.

### 4. **File Management System**
   - **Persistent Data**: Uses text files to store records of violations, accidents, vehicles, etc.
   - **Dynamic File Handling**: Data is read and written dynamically for real-time updates.

### 5. **User Interface with Color-Coding**
   - **CLI Interface**: Clean, simple, and effective command-line interface.
   - **Color-Coded Alerts**: Visual feedback through color-coded messages to enhance readability and UX:
     - **Green**: Success messages ✅
     - **Red**: Error or alert messages 🚨
     - **Yellow**: Informational messages ⚠️

### 6. **Optimized Algorithms and Data Structures**
   - **Graph Representation**: Cities and roads are represented as a graph structure for optimized pathfinding.
   - **Dijkstra’s Algorithm**: Used to calculate the shortest path for emergency vehicles and regular traffic flow.

---

## 🛠 Functionality Overview

### 🚓 **Police Panel**
- **Emergency Request**: Handle emergency vehicle requests and control traffic signals.
- **Report Traffic Violations**: Police can register and manage violations.
- **Issue Traffic Warnings**: Issue warnings to drivers violating traffic rules.
- **VIP Request**: Handle VIP requests and prioritize their vehicles.
- **Report Accident**: Add and manage traffic accident reports.
- **Register Vehicle Info**: Register vehicle details for law enforcement and record-keeping.

### 👨‍💼 **Admin Panel**
- **Traffic Status**: View real-time traffic conditions at various intersections.
- **Control Traffic Signals**: Admins can manually control traffic signals based on current traffic flow.
- **Incident Management**: Admins can handle incidents like accidents and disruptions.
- **Traffic Violations Records**: Admins can view and manage violation records.
- **Information Records**: Admins can maintain and access information about vehicles and traffic conditions.
- **Shortest Path**: View and calculate the shortest path between cities using Dijkstra’s algorithm.

---

## ⚙️ Optimizations & Design

- **Efficient Algorithms**: Dijkstra's algorithm optimizes pathfinding, making the system responsive even with a large dataset of cities and intersections.
- **Modular Structure**: The code is divided into modules, including traffic management, file handling, and user authentication, ensuring maintainability.
- **Color-Coded UI**: The system uses **ANSI escape codes** for color-coding success, error, and informational messages.
- **File-Based Data Storage**: Uses **text files** to persist traffic data, violations, accidents, and more for easy retrieval.

---

## 📖 Technologies Used

- **Programming Language**: C
- **Data Structures**: Graphs, Linked Lists, Arrays
- **Algorithms**: Dijkstra's Shortest Path Algorithm
- **File Management**: Text-based file handling for persistent storage
- **Color-Coding**: ANSI Escape Codes for terminal color formatting

---

## 🚀 How to Run the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/U-Turn.git
   cd U-Turn
