#!/bin/bash
#chmod +x AllParameters.sh
declare -a VariablesSize
declare -a VariablesNames
declare -A Matrix

NumVariables=8
VariablesSize[1]=1
VariablesSize[2]=1
VariablesSize[3]=17
VariablesSize[4]=2
VariablesSize[5]=3
VariablesSize[6]=3
VariablesSize[7]=3
VariablesSize[8]=3
VariablesNames[1]="Adjacency"
VariablesNames[2]="Unclearable"
VariablesNames[3]="Seed"
VariablesNames[4]="MisfoldRate"
VariablesNames[5]="DiffusionSpeed"
VariablesNames[6]="ActiveTransport"
VariablesNames[7]="SynapticTransfer"
VariablesNames[8]="LongPref"

Matrix[1,1]=1

Matrix[2,1]=1

Matrix[3,1]=0
Matrix[3,2]=1
Matrix[3,3]=2
Matrix[3,4]=3
Matrix[3,5]=4
Matrix[3,6]=5
Matrix[3,7]=6
Matrix[3,8]=7
Matrix[3,9]=8
Matrix[3,10]=9
Matrix[3,11]=10
Matrix[3,12]=11
Matrix[3,13]=12
Matrix[3,14]=13
Matrix[3,15]=14
Matrix[3,16]=15
Matrix[3,17]=16

Matrix[4,1]=0.080
Matrix[4,2]=0.090

Matrix[5,1]=0
Matrix[5,2]=50
Matrix[5,3]=500

Matrix[6,1]=0
Matrix[6,2]=0.0001
Matrix[6,3]=0.001

Matrix[7,1]=0
Matrix[7,2]=1
Matrix[7,3]=2

Matrix[8,1]=0.01
Matrix[8,2]=1
Matrix[8,3]=100
