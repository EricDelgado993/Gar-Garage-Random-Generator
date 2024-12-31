# Car Garage Random Generator

## **Project Overview**
The **Car Garage Random Generator** is a C++ program designed to simulate a virtual car garage containing 100 randomly generated cars. Each car has unique attributes, including brand, model, color, and speed. The program organizes this data into structured files, enabling easy storage, retrieval, and analysis. This project demonstrates essential programming concepts such as randomization, file handling, error checking, and data sorting in a practical and engaging way.

---

### 📁 **Implementation Files**
1. [Car.h](https://github.com/EricDelgado993/Gar-Garage-Random-Generator/blob/main/Car%20Garage%20Project/Car.h):
   - Structures:
     - `Car`: Represents a car with brand, model, color, and speed.
     - `Output`: Contains file paths for output files.
2. **CarFunctions.h**:
   - Declares functions for:
     - Reading input data.
     - Generating random cars.
     - Writing unsorted and sorted data.
     - Generating organized output files.

---

## **Features**

### **Random Car Generation**
- Creates 100 cars with randomized attributes:
  - **Brand**: Loaded from a predefined `brands.txt` file.
  - **Model**: Loaded from a predefined `models.txt` file.
  - **Color**: Loaded from a predefined `colors.txt` file.
  - **Speed**: Randomly assigned between `0` and `150`.

### **Command-Line Input**
- Accepts three input files via command-line arguments in the order:
  1. `brands.txt`
  2. `colors.txt`
  3. `models.txt`

### **Organized File Outputs**
- **Unsorted Data**: All car data stored in `unsortedData.txt`.
- **Sorted Data**: Cars can be sorted by:
  - Brand
  - Model
  - Color
  - Output saved to `sortedData.txt`.
- **Category-Based Organization**:
  - Folder structure for brands, colors, and models.
  - Separate files for cars categorized by speed:
    - `fastCars.txt` for speeds > 70.
    - `slowCars.txt` for speeds ≤ 70.
- **Summary Statistics**:
  - `garageStats.txt` summarizes the total count of cars, brands, models, and colors.

### **Error Handling**
- Ensures proper execution by validating:
  - Correct number of arguments.
  - Valid and accessible input files.
  - Non-empty data in the input files.

---

### **Core Functionalities**
1. **Input Handling**:
   - Reads data from `brands.txt`, `colors.txt`, and `models.txt`.
2. **Garage Creation**:
   - Generates an array of 100 cars with random attributes.
3. **Data Sorting**:
   - Sorts cars by selected attributes and saves to `sortedData.txt`.
4. **Output Generation**:
   - Creates category-based folders and files for structured storage.
   - Generates a statistics summary in `garageStats.txt`.

---

This project serves as a great introduction to combining multiple programming concepts into a practical and real-world application.
