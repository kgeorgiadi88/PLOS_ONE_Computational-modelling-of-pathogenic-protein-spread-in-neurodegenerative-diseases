function [LoadDirectories, SaveDirectories, VariablesSize, VariablesNames] = GetInputFoldersNew
BaseLoadPath = '/Users/kgeorgiadi/Documents/PhD/Results/PLOS2017/';
BaseSavePath = '/Users/kgeorgiadi/Documents/PhD/Results/PLOS2017/';

NumVariables=0;

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=2;
VariablesNames{NumVariables}='Adjacency';

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=2;
VariablesNames{NumVariables}='Unclearable';

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=17;
VariablesNames{NumVariables}='Seed';

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=2;
VariablesNames{NumVariables}='MisfoldRate';

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=3;
VariablesNames{NumVariables}='DiffusionSpeed';

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=3;
VariablesNames{NumVariables}='ActiveTransport';

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=3;
VariablesNames{NumVariables}='SynapticTransfer';

NumVariables=NumVariables+1;
VariablesSize(NumVariables)=3;
VariablesNames{NumVariables}='LongPref';


CurrentExperiment = ones(1,NumVariables);
TotalExperiments = prod(VariablesSize);
LoadDirectories = cell(0,0);
SaveDirectories = cell(0,0);

for experiment = 1:TotalExperiments
	DIRECTORYload = BaseLoadPath;
	DIRECTORYsave = BaseSavePath;
	for j=1:NumVariables
		DIRECTORYload = strcat(DIRECTORYload, VariablesNames{j}, num2str(CurrentExperiment(j)),'/');
		DIRECTORYsave = strcat(DIRECTORYsave, VariablesNames{j}, num2str(CurrentExperiment(j)),'/');
	end
	LoadDirectories{size(LoadDirectories,2)+1} = DIRECTORYload;
	SaveDirectories{size(SaveDirectories,2)+1} = DIRECTORYsave;
	
    if(experiment < TotalExperiments)
        k = NumVariables;
        CurrentExperiment(k) = CurrentExperiment(k) + 1;
        while(1)
            if(CurrentExperiment(k) > VariablesSize(k))
                CurrentExperiment(k) = 1;
                k = k - 1;
                CurrentExperiment(k) = CurrentExperiment(k) + 1;
            else
                break;
            end
        end
    end
end
end
