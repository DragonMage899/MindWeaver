# Machine Learning Introduction
- Given some known data make a prediction of what comes next

# Types of ML
### Supervised Learning 
- Train on labelled data
- Use input to predict the output
- This is achieved by getting the model to learn mappings between inputs and outputs 
- This then allows it to generalise well to new unseen data

**Types of Supervised learning problems**
- Regression
	- Output variable is continuous (predicting a stock price)
- Classification
	- Output variable is categorical (email spam detection)


**Drawbacks**
- Need a large amount of data
- Over fitting:
	- Model does well on training data but poor on test data 
- Bias
- Hard to scale 

## Unsupervised learning
- No labels
- Tries to find patterns 
- Goal is to explore and understand data

#### Types
**Clustering**
- Group similar data based on features

**Dimensionality Reduction**
- Reduce Amount of feature and preserve important information 

**Anomaly Detection**
- Identifying irregular data within a data set  (ids)

Association Rule Learning
- Discover relationships between variables in a data set

#### Disadvantages 
Ambiguity in results 
- no labels makes it hard to judge evaluations 

Interpret-ability
- The patterns discovered may not be an actionable interpretation

## Semi Supervised
Semi Supervised: Between supervised and unsupervised 
- Use both labelled and unlabelled data
- Use a small amount of labelled data to guide the learning process
- Use large amounts of unlabelled data for generality

## Self Supervised
Falls under unsupervised 
- Train on unlabelled data 
- Creates artificial supervision signals derived from the data
- Labels are generated automatically from input data
- Goal: Learn useful representations or features from data without requiring human annotation
- BERT RoBERTa GPT

## Reinforcement learning 
Agent learns to make decisions by interacting with the environment 
- Goal: Learn a policy that maximises cumulative reward over time  
Learn through trial and error 
- Agent takes an action
- Observes resulting state and reward
- Adjust behaviour to maximise future rewards 

# Data Formulation
- Universe of objects
- Each object has variables (attributes) that describe it's properties
- Set if attribute values corresponding to an object is an instance 
- Data set -> Complete set of data available to the program   
- Labelled if one attribute has special significance 
	- Aim is then to predict that value 
	- Commonly refered to as class
- If no such variable / class exists we consider the data set unlabelled

#### Variable Types
![[Pasted image 20250531162724.png]]
![[Pasted image 20250531162901.png]]


## Pre Processing 
Accounting for duplicates, missing (perhaps a missing feature) or erroneous data 


## Normalisation 
Scaling the data to a certain range 
- Good for ensuring outliers don't make a significant impact 

![[Pasted image 20250531163128.png]]

![[Pasted image 20250531163134.png]]

# KNN
Memorise the training data 
When given new data, find K closest examples and make a prediction
![[Pasted image 20250531163341.png]]
![[Pasted image 20250531163401.png]]

#### Example
![[Pasted image 20250531163451.png]]
![[Pasted image 20250531163521.png]]


# Artificial Neural Networks
![[Pasted image 20250531164222.png]]

![[Pasted image 20250531164243.png]]

p -> input
w -> weights
b -> bias (input of 1)
n -> sum of weighted inputs and bias
	![[Pasted image 20250531164410.png]]
f -> Activation function
- Takes in n as input
- determines neurons output 


Training a neural network
- Using algorithms (activation functions, learning algorithms) to determine the weights and biases 
- A training set provides input that is used to train the neural network

![[Pasted image 20250531164841.png]]
![[Pasted image 20250531164907.png]]
![[Pasted image 20250531164935.png]]
![[Pasted image 20250531164944.png]]


## McCulloch-Pitts Neuron
Neuron with a binary output 
Each neuron has a threshold
Activation function
	![[Pasted image 20250531165350.png]]


![[Pasted image 20250531165411.png]]

#### EX
Design a McCulloch Neuron to represent an OR operation
![[Pasted image 20250531165605.png]]

Two inputs thus two weights 

f(n) = W1 + W2
Set 
Theta = 2
W1 = 2
W2 = 2

![[Pasted image 20250531165718.png]]

For real world problems you'd need to create an algorithm to set the weights as manual would be tedious 

## Linear Separability 
Doing the same for XOR would not be as easy
XOR us not a linear separable function and thus more than one layer would be required 

![[Pasted image 20250531165950.png]]
For OR we can draw one straight line dividing the section separating + and -.
We can't do this for XOR.
A multi layer neural network is required.


# Single Layer Perceptron 
Neural Networks fall into two categories 
- Pattern Classification
- Pattern Association

A perceptron is a feed forward neural network that performs pattern classification
- single or multi layered

We use a learning algorithm to determine the weights and biases.
Performed over epochs, each epoch updates the weights and biases.
Convergence is determined by the set of weights and biases.
Perceptron does classification.
**Input**: attributes for classification problem
**Output**: Class

### **Binary Classification**
- Input vector either belongs to the class or it does not

##### Example
Sort fruit according to shape, weight and texture.
Shapes: Round(1), Elliptical(-1)
Texture: Smooth(1), Rough(-1)
Weight: >0.5kg(1), <=0.5kg(-1)

Suppose we now want to seperate:
oranges [1,-1,-1] from apples [1,1,-1]

Let class apples = 1
Let class oranges = -1

![[Pasted image 20250601135848.png]]
![[Pasted image 20250601135904.png]]

Need to find W and b
![[Pasted image 20250601135935.png]]





### **Multi class Classification**
- Input vector can belong to any n>1 classes 

##### Example
Following from the previous example suppose we also need to separate grapefruit as well.
grapefruit = [1,-1,1]

![[Pasted image 20250601140130.png]]
![[Pasted image 20250601140145.png]]
![[Pasted image 20250601140241.png]]



Activation function for binary training data
![[Pasted image 20250601140326.png]]
![[Pasted image 20250601140409.png]]

m -> number of inputs

**Perceptron Learning Algorithm**
- NB problem must be a binary classification 
- Linearly separable -> only need a single layer unlike in multi class 
number of output (j) = 1 [binary classification]

![[Pasted image 20250601140635.png]]



#### Example
![[Pasted image 20250601143451.png]]
![[Pasted image 20250601135848.png]]
![[Pasted image 20250601143515.png]]
![[Pasted image 20250601143520.png]]
![[Pasted image 20250601143527.png]]

# Multi layer perceptron
- Use propagation as our leaning algorithm 

MLP is a type of ANN that consists of an input layer, hidden layer and output layer .
MLP's are a feed forward network.

### Features
![[Pasted image 20250601144341.png]]
![[Pasted image 20250601144424.png]]

skip ...

# Hop field 
skip ...

# Deep Neural Networks
Neural network with many hidden layers that can be feed forward or recurrent.
Can do supervised and unsupervised learning.
Accuracy and Loss function used to measure performance.

# Convolutional Networks 
![[Pasted image 20250602174306.png]]

# Decision Trees 
![[Pasted image 20250606061156.png]]'

![[Pasted image 20250606061210.png]]
![[Pasted image 20250606061217.png]]
![[Pasted image 20250606061225.png]]

Entropy = 0.94


Gain
![[Pasted image 20250606061308.png]]
![[Pasted image 20250606061442.png]]
![[Pasted image 20250606061548.png]]
![[Pasted image 20250606061616.png]]

