Code and data for PLOS One submission:
PONE-D-17-37798R1
Computational modelling of pathogenic protein spread in neurodegenerative diseases

BSD licensed code.

Note that the code only works on UNIX. Not on Windows or Mac.

Let us assume that you downloaded and extracted to:

\Folder1\

You should have the following folders:

\Folder1\ClusterScripts\
\Folder1\MATLAB\
\Folder1\ncdemo\

In order to make sure that the code will run perform the following steps:

1) You first need to install NEURON:
https://neuron.yale.edu/neuron/

2) Download the neural network files and code from:
https://senselab.med.yale.edu/MicroCircuitDB/showModel.cshtml?model=136095#tabs-1

Let us assume that you downloaded to:

\Folder2\

You should have:

\Folder2\ncdemo\

Follow the intructions in \Folder2\ncdemo\readme.txt in order to install the code properly.

3) copy the following files from \Folder1\ncdemo\ to \Folder2\ncdemo\

Adjacency.dat
DelaysToLoad.dat
DelaysToLoad1.dat
DelaysToLoad2.dat
Finished.dat
ParameterSet.dat
mosinit.hoc

4) The actual code is in mosinit.hoc (almost all of the code related to neurodegenerative disease modelling is either at the start or at the end of the file).
By changing the numbers in ParameterSet.dat, you can change the parameters of the model (such as diffusion speed).

5) After setting your desired parameters in ParameterSet.dat, simply run:
./Folder2/ncdemo/x86_64/special mosinit.hoc

Simulations can take hours. They produce .dat files which are used for postprocessing (primarily keeping track of concentration, toxicity over time, as well as the order of neuronal deaths, neuronal types, etc.)

6) All postprocessing of the simulation results and figures are done with MATLAB. The code is in /Folder1/MATLAB/. However, note that the code has been intended for use in conjunction with a cluster. There are scripts for running it on a cluster in /Folder1/ClusterScripts/. See the instructions in the cluster folder for more details.



