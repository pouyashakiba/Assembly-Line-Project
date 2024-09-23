# Assembly Line Project

## Project Overview

This project simulates an assembly line for processing customer orders for various furniture items. It models the assembly line process with several key components such as workstations, stations, and customer orders. The program is capable of handling multiple customer orders, processing them across different stations, and tracking inventory for each item.

## Features

- **Customer Orders:** Handles multiple orders from various customers.
- **Stations:** Each station processes a specific item required for the customer's order.
- **Workstations:** Workstations are specialized stations that process orders and pass them along the assembly line.
- **Inventory Management:** Tracks the inventory of items at each station and updates when items are used in orders.
- **Order Processing:** Automatically processes orders as they move through the line.

## Project Structure

- `assembly_line.txt`: Contains a mapping of station relationships for the assembly line.
- `customer_order.cpp` / `customer_order.h`: Handles customer orders and manages their data.
- `line_manager.cpp` / `line_manager.h`: Manages the workflow of the assembly line and the processing of orders.
- `station.cpp` / `station.h`: Defines the behavior and attributes of each station in the assembly line.
- `utilities.cpp` / `utilities.h`: Provides utility functions to support the project.
- `workstation.cpp` / `workstation.h`: Extends the functionality of stations to handle workstations.
- `stations_1.txt` / `stations_2.txt`: Files containing inventory details for the various furniture items processed by the assembly line.
- `customer_orders.txt`: Sample input data for customer orders.

## Dependencies

- Standard C++ Libraries (STL)
- No external dependencies required.

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
