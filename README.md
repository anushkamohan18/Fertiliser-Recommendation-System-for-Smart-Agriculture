# 🌾 Fertiliser Recommendation System for Smart Agriculture

This project presents a **smart fertiliser recommendation system** developed using machine learning to assist in precision agriculture. By analyzing soil properties, crop types, and environmental conditions, the system suggests the most suitable fertiliser to enhance yield and promote sustainable farming.

---

## 🚀 Features

- **Intelligent Fertiliser Recommendations**  
  Suggests optimal fertilisers based on real-time soil and crop parameters.

- **Data-Driven Decision Making**  
  Uses trained ML models to generate accurate, tailored recommendations.

- **Interactive Visualizations**  
  Includes charts and plots for better understanding of data and predictions.

- **User-Friendly Notebook Interface**  
  Simple, modifiable Jupyter Notebook design for easy experimentation.

- **IoT-Ready Integration**  
  Includes Arduino code for soil sensors to automate data collection.

---

## 🧠 Tech Stack

- **Language**: Python  
- **Libraries**: `pandas`, `numpy`, `scikit-learn`, `matplotlib`, `seaborn`  
- **Tools**: Jupyter Notebook, Colab, Arduino  
- **Model**: Random Forest (trained and saved as `.pkl`)  
- **Hardware Integration**: Arduino code for soil sensors (via `.ino` files)

---

## 📁 Project Structure

```plaintext
Fertiliser-Recommendation-System-for-Smart-Agriculture/
├── IOT_soil_fully_updated.xlsx           # Input dataset
├── fertiliser_recommendation.ipynb       # Main ML notebook
├── fertilizer_model.pkl                  # Trained ML model
├── label_encoder.pkl                     # Saved label encoder
├── soilcode.ino                          # Arduino soil sensor script
├── soilfinal.ino                         # Final Arduino script version
├── soilarduino.ino                       # Additional Arduino script
├── confusion_matrix.png                  # Confusion matrix visualization
├── feature_importance.png                # Feature importance plot
├── fertilizer_distribution.png           # Fertiliser distribution chart
├── table1.png                            # Summary or reference table
├── Smart_Fertilizer_System_Presentation.pdf  # Project presentation slides
├── README.md                             # Project documentation (this file)
├── Requirement.txt            
```

---

## ⚙️ How It Works

1. **Input Parameters**  
   User provides soil nutrient levels (N, P, K), pH, moisture, and crop type.

2. **Preprocessing**  
   Data is cleaned and encoded using preprocessing pipelines.

3. **Prediction**  
   The model predicts the optimal fertiliser class/type for the given inputs.

4. **Output & Insights**  
   Visual outputs include feature importance, confusion matrix, and fertiliser distribution.

---

## 📦 Installation & Setup

```bash
# Clone the repository
git clone https://github.com/anushkamohan18/Fertiliser-Recommendation-System-for-Smart-Agriculture.git
cd Fertiliser-Recommendation-System-for-Smart-Agriculture

# Install required dependencies
pip install -r requirements.txt

# Run the notebook
jupyter notebook
```
----
## 🙏 Acknowledgements

- Agricultural datasets and resources from open data portals.
- Open-source Python libraries and the Jupyter community.
## 📥 Usage

- Open the main notebook.
- Follow the instructions to load data, train the model (if required), and generate fertiliser recommendations.
- Modify input parameters to see recommendations for different scenarios.


---

## 🤝 Contributing

Contributions are welcome! Please open issues or pull requests for improvements, bug fixes, or new features.

---

## 📄 License

This project is licensed under the MIT License.

---
