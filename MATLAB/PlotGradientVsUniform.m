function PlotGradientVsUniform( AllNumbers, Load_Directories, Save_Directories, Save_Directory, savepdf )
FontSizeAll = 18;
for CurrentExperiment = [1:prod(AllNumbers)]
	close all;
	Load_CurrentDirectory = Load_Directories{CurrentExperiment};
	Save_CurrentDirectory = Save_Directories{CurrentExperiment};
    VideoDamage = dlmread([Load_CurrentDirectory 'VideoDamage.dat']);
    MetaData = dlmread([Load_CurrentDirectory 'SaveMetaData.dat']);
    NumNeurons = MetaData(1);
	CurrentExperiment
	
	%What frame should the video stop at
	VideoStopAt = 0;
	for frame = size(VideoDamage,2):-1:1
		if(any(VideoDamage(:,frame) > 0))
			VideoStopAt = frame;
			break;
		end
	end
	
	VideoDamage = VideoDamage(:,1:VideoStopAt);
	
	
	
	clear DistancesToMean;
	for t = 1:size(VideoDamage,2)
		DistancesToMean(t) = sqrt(sum((VideoDamage(:,t)-mean(VideoDamage(:,t))).^2)/(size(VideoDamage,1)-1));
	end
	
	width = 30;
	height = 15;
	DistancesHistFigure = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
		'PaperUnits','centimeters',...
		'PaperSize',[width height],...
		'PaperPositionMode','auto',...
		'InvertHardcopy', 'on',...
		'Renderer','painters'...
		);
	plot(DistancesToMean)	
	set(gca,'FontSize',FontSizeAll)
	title(['If low value then high uniformity ' num2str(mean(DistancesToMean)) ' (low=unif)'],'FontSize',FontSizeAll)
	xlabel('Time','FontSize',FontSizeAll)
	ylabel('Uniformity value','FontSize',FontSizeAll)
	if(savepdf)
		set(gcf, 'Color', 'w');
		export_fig([Save_CurrentDirectory 'GradUnifDistancesMean.pdf'], '-pdf', '-painters', '-a1', '-q101')
	end
	
	DistancesToMeanMeans(CurrentExperiment) = mean(DistancesToMean);
	
	
	
	close all;
end
save([Save_Directory 'DistancesToMeanMeans.mat'], 'DistancesToMeanMeans');

end


% plot(DistancesToMeanMeans(1:2:end),'*-')
% 
% load([Save_Directory 'DistancesToMeanMeans.mat']);
