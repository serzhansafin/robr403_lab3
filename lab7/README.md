# This is for lab7 ROBT403
### The error was initially:45,61%
![img1](images/img1.PNG)
![img1](images/img2.PNG)
### Then tanh Layer was added:
![img1](images/img3_with_tanh.PNG)
### and the result was like following:
### much worser than before err - 108.02%
![img1](images/img4_with_tanh.PNG)

### then several layers were added (512-256-128)
### the result showed better
![img1](images/img5_with_sevLayers.PNG)
![img1](images/img6_with_sevLayers.PNG)
### after that maxEpochs was changed to 30 and miniBatchSize to 200 with architecture 512-256-128 with leakyReluLayer
![img1](images/img8_512_256_128_ep30_batchsize200.PNG)
![img1](images/img9_512_256_128_ep30_batchsize200.PNG)
### tanhLayer several times:
![img1](images/img10_sevLayers_tanhLayer.PNG)
![img1](images/img11_sevLayers_tanhLayer.PNG)
