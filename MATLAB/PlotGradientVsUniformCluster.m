function PlotGradientVsUniformCluster( CurrentLoadDirectory, CurrentSaveDirectory,savepdf )
FontSizeAll = 18;
VideoDamage = dlmread([CurrentLoadDirectory 'VideoDamage.dat']);
%What frame should the video stop at
VideoStopAt = 0;
for frame = size(VideoDamage,2):-1:1
    if(any(VideoDamage(:,frame) > 0))
        VideoStopAt = frame;
        break;
    end
end
VideoDamage = VideoDamage(:,1:VideoStopAt);

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
plot(linspace(0,10*size(DistancesToMean,2), size(DistancesToMean,2)),DistancesToMean)
set(gca,'FontSize',FontSizeAll)
title(['If low value then high uniformity. Mean value over time:' num2str(mean(DistancesToMean))],'FontSize',FontSizeAll)
xlabel('Time','FontSize',FontSizeAll)
ylabel('Non uniformity value','FontSize',FontSizeAll)
if(savepdf)
    set(gcf, 'Color', 'w');
    export_fig([CurrentSaveDirectory 'GradUnifDistancesMean.pdf'], '-pdf', '-painters', '-a1', '-q101')
end

dlmwrite([CurrentSaveDirectory 'GradUnifMeanValue.dat'], max(DistancesToMean));
dlmwrite([CurrentLoadDirectory 'GradUnifMeanValue.dat'], max(DistancesToMean));

end


