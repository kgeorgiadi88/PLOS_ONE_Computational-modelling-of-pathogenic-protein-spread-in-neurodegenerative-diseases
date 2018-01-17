function [load_directories, save_directories, allnumbers, sd] = GetInputFolders
BaseLoadPath = '/Users/kgeorgiadi/Documents/PhD/ClusterDownload/';
BaseSavePath = '/Users/kgeorgiadi/Documents/PhD/ExperimentsAndResults/';

NumVariables=8;

VariablesSize(1)=1;
VariablesNames{1}='Adjacency';
MatrixVariables(1,1)=1;

VariablesSize(2)=1;
VariablesNames{2}='Seed';
for i=1:17
	MatrixVariables(2,i)=i-1;
end

VariablesSize(3)=3;
VariablesNames{3}='MisfoldRate';
MatrixVariables(3,1)=0.0655;

VariablesSize(4)=3;
VariablesNames{4}='DiffusionSpeed';
MatrixVariables(4,1)=50;
MatrixVariables(4,2)=100;
MatrixVariables(4,3)=500;

VariablesSize(5)=3;
VariablesNames{5}='ActiveTransport';
MatrixVariables(5,1)=0.0001;
MatrixVariables(5,2)=0.0003;
MatrixVariables(5,3)=0.0005;

VariablesSize(6)=2;
VariablesNames{6}='SynapticTransfer';
MatrixVariables(6,1)=0.001;
MatrixVariables(6,2)=0.01;
MatrixVariables(6,3)=0.1;

VariablesSize(7)=3;
VariablesNames{7}='LongPref';
MatrixVariables(7,1)=1;
MatrixVariables(7,2)=10;
MatrixVariables(7,3)=100;

VariablesSize(8)=2;
VariablesNames{8}='ProtEffect';
MatrixVariables(8,1)=1;
MatrixVariables(8,2)=2;

sd = [MatrixVariables(1,1) MatrixVariables(8,1)];

allnumbers = fliplr(VariablesSize);
VariablesOrder = [2 8 7 6 5 4 3 1];
VariablesSizesOrdered = VariablesSize(VariablesOrder);


CurrentExperiment = ones(1,NumVariables);
TotalExperiments = prod(VariablesSize);
load_directories = cell(0,0);
save_directories = cell(0,0);

for experiment = 1:TotalExperiments
	DIRECTORYload = BaseLoadPath;
	DIRECTORYsave = BaseSavePath;
	for j=1:NumVariables
		DIRECTORYload = strcat(DIRECTORYload, VariablesNames{j}, num2str(CurrentExperiment(j)),'/');
		DIRECTORYsave = strcat(DIRECTORYsave, VariablesNames{j}, num2str(CurrentExperiment(j)),'/');
	end
	load_directories{size(load_directories,2)+1} = DIRECTORYload;
	save_directories{size(save_directories,2)+1} = DIRECTORYsave;
	
	if(experiment < TotalExperiments)
		k = 1;
		j = VariablesOrder(k);
		CurrentExperiment(j) = CurrentExperiment(j) + 1;
		while(1)
			if(CurrentExperiment(j) > VariablesSize(j))
				k = k + 1;
				CurrentExperiment(j) = 1;
				j = VariablesOrder(k);
				CurrentExperiment(j) = CurrentExperiment(j) + 1;
			else
				break;
			end
		end	
	end
end
end

