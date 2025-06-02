# Medicine Inventory System

A comprehensive C++ console application for managing pharmacy inventory using multiple data structures. This system provides a complete solution for tracking medicines, their expiry dates, quantities, and prices with different implementation approaches.

> **Note**: This is a collaborative project developed as part of a data structures and algorithms course, demonstrating teamwork and practical implementation of multiple data structure concepts.

## 🚀 Features

- **Multiple Data Structure Implementations**:
  - Doubly Linked List
  - Stack-based Storage
  - Queue-based Storage
- **Medicine Management**:
  - ➕ Add new medicines with unique ID validation
  - 🔍 Search by name, ID, or expiry date
  - 📊 Sort by name, ID, or expiry date
  - ✏️ Update medicine details
  - 📋 Display all medicines in formatted tables
- **Expiry Management**:
  - 🗓️ Date validation (MM/YYYY format)
  - ⚠️ Auto-delete expired medicines
  - 📅 Expiry tracking and alerts
- **User Interface**:
  - 🎨 Colorized terminal output
  - 📝 Input validation and error handling
  - 🖱️ Menu-driven interface

## 📁 Project Structure

```
Medicine-Inventory-System/
├── main.cpp              # Main program with menu system
├── head.h                # Header declarations
├── head.cpp              # Core structures and utility functions
├── linkedlist.cpp        # Doubly linked list implementation
├── stack.cpp             # Stack-based implementation
├── queue.cpp             # Queue-based implementation
├── compare.cpp           # Performance comparison utilities
├── tempCodeRunnerFile.cpp# Temporary compilation file
├── Menu Structure.docx   # Documentation
└── README.md             # Project documentation
```

## 🏗️ Architecture

### Medicine Structure

```cpp
struct Medicine {
    int id;                // Unique identifier
    string name;           // Medicine name
    double price;          // Price per unit
    int quantity;          // Available quantity
    string expiryDate;     // Expiry date (MM/YYYY)
    Medicine *next;        // Next node pointer
    Medicine *prev;        // Previous node pointer (for doubly linked list)
}
```

### Data Structure Implementations

1. **Doubly Linked List** (`linkedlist.cpp`)

   - Bi-directional traversal
   - Efficient insertion and deletion
   - QuickSort implementation for sorting

2. **Stack** (`stack.cpp`)

   - LIFO (Last In, First Out) operations
   - QuickSort for sorting algorithms
   - Top-based medicine management

3. **Queue** (`queue.cpp`)
   - FIFO (First In, First Out) operations
   - Bubble sort implementation
   - Front and rear pointer management

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler**: GCC 7.0+ or equivalent
- **Operating System**: Linux, macOS, or Windows
- **Terminal**: Color support recommended

### Installation

1. **Clone the repository**:

   ```bash
   git clone <repository-url>
   cd Medicine-Inventory-System
   ```

2. **Compile the program**:

   ```bash
   g++ -o medicine_system main.cpp
   ```

3. **Run the application**:
   ```bash
   ./medicine_system
   ```

## 💻 Usage

### Main Menu Options

When you run the program, you'll see:

```
1. Linked List
2. Stack
3. Queue
4. Exit
```

### Medicine Management Operations

Each data structure implementation provides:

1. **Add Medicine** - Input medicine details with validation
2. **Search by Name** - Find medicines by exact name match
3. **Search by ID** - Locate medicine using unique identifier
4. **Search by Expiry Date** - Find medicines expiring in specific month/year
5. **Sort by Name** - Alphabetical sorting
6. **Sort by ID** - Numerical ID sorting
7. **Sort by Expiry Date** - Chronological sorting
8. **Display All Medicines** - Formatted table view
9. **Update Medicine** - Modify existing medicine details
10. **Auto-Delete Expired** - Remove medicines past expiry date

### Input Formats

- **Medicine ID**: Integer (must be unique)
- **Medicine Name**: String (spaces allowed)
- **Price**: Decimal number
- **Quantity**: Integer
- **Expiry Date**: MM/YYYY format (e.g., 06/2025)

### Example Usage

```
Enter medicine ID: 101
Enter medicine name: Aspirin
Enter medicine price: 15.50
Enter medicine quantity: 100
Enter expiry date (MM/YYYY): 12/2025
```

## 🔧 Key Features Explained

### Input Validation

- **ID Uniqueness**: Prevents duplicate medicine IDs
- **Date Format**: Validates MM/YYYY format
- **Numeric Input**: Handles invalid number inputs gracefully
- **Error Recovery**: Clear error messages and retry prompts

### Sorting Algorithms

- **Linked List**: QuickSort implementation
- **Stack**: QuickSort with LIFO structure
- **Queue**: Bubble Sort with FIFO structure

### Memory Management

- **Automatic Cleanup**: Destructors handle memory deallocation
- **Dynamic Allocation**: Efficient memory usage
- **Leak Prevention**: Proper node deletion

### Color-Coded Interface

- 🟢 **Green**: Success messages
- 🔴 **Red**: Error messages and warnings
- 🔵 **Cyan**: Information and headers
- 🟡 **Yellow**: Warnings and alerts

## 🛠️ Development

### Compilation Options

```bash
# Basic compilation
g++ -o medicine_system main.cpp

# With debugging symbols
g++ -g -o medicine_system main.cpp

# With optimization
g++ -O2 -o medicine_system main.cpp

# With all warnings
g++ -Wall -Wextra -o medicine_system main.cpp
```

### Code Structure

- **Modular Design**: Each data structure in separate file
- **Consistent Interface**: Same operations across implementations
- **Error Handling**: Comprehensive input validation
- **Performance**: Optimized algorithms for each structure

## 📊 Performance Comparison

The system includes performance measurement utilities in `compare.cpp` for analyzing:

- Operation execution times
- Memory usage patterns
- Algorithm efficiency comparisons

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Create a Pull Request

### Coding Standards

- Follow existing code style
- Add comments for complex algorithms
- Validate all user inputs
- Handle edge cases appropriately

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🐛 Known Issues

- Terminal color codes may not work on all systems
- Date validation limited to MM/YYYY format
- No persistent storage (data lost on program exit)

## 🔮 Future Enhancements

- [ ] File-based data persistence
- [ ] Advanced search filters
- [ ] Batch medicine import/export
- [ ] Graphical user interface
- [ ] Database integration
- [ ] Barcode scanning support
- [ ] Multi-user access control
- [ ] Inventory reporting system

## 📞 Support

For questions, issues, or contributions:

- Open an issue on GitHub
- Review the documentation
- Check existing discussions

## 🙏 Acknowledgments

- **Collaborative Development**: This project was developed through teamwork and collaboration
- Built as a demonstration of data structure implementations
- Showcases practical applications of C++ programming concepts
- Educational project for understanding algorithmic complexity
- **Team Effort**: Demonstrates effective collaboration in software development

---

**Note**: This system is designed for educational purposes and demonstrates various data structure implementations. For production use, consider adding database persistence and enhanced security features.
