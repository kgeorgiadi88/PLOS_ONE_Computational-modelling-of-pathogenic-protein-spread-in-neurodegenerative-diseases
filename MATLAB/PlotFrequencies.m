function PlotFrequencies( CurrentLoadDirectory, CurrentSaveDirectory, savepdf, t, NumTypePerColumn)
FontSizeAll = 18;
load([CurrentLoadDirectory 'Everything.mat'], 'VideoConcentrations', 'VideoDamage', 'TimestepsPerFrame', 'NumColumns', 'dt', 'VideoColors' );
SummaryDamage = dlmread([CurrentLoadDirectory 'SummaryDamage.dat']);
SummaryFrequencies = dlmread([CurrentLoadDirectory 'SummaryFrequencies.dat']);

%Find when Concentration reaches maximum
stopat = size(VideoConcentrations,2);
for i = size(VideoConcentrations,2):-1:1
    if(any(VideoConcentrations(:,i) > 0))
        stopat = i;
        break;
    end
end
% 	for neuron = 1:size(VideoConcentrations,1)
% 		[tempval, tempindex] = max(VideoConcentrations(neuron,:));
% 		VideoConcentrations(neuron,tempindex:end) = tempval;
% 		if(neuron <= size(SummaryConcentrations,1))
% 			[tempval, tempindex] = max(SummaryConcentrations(neuron,:));
% 			SummaryConcentrations(neuron,tempindex:end) = tempval;
% 		end
% 	end

final = (stopat-1)*TimestepsPerFrame*dt;
for column = 0:NumColumns-1
    width = 2*25;
    height = 2*10;
    h1 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
        'PaperUnits','centimeters',...
        'PaperSize',[width height],...
        'PaperPositionMode','auto',...
        'InvertHardcopy', 'on',...
        'Renderer','painters'...
        );
    hold on;
    for type = 1:40
        if(NumTypePerColumn(type)>0)
            if(type == t.E2)
                ColorFrequency = VideoColors(1,:);
                subplot(2,2,1);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.E2B)
                ColorFrequency = VideoColors(3,:);
                subplot(2,2,1);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I2)
                ColorFrequency = VideoColors(5,:);
                subplot(2,2,1);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I2L)
                ColorFrequency = VideoColors(10,:);
                subplot(2,2,1);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
                legend('L2RS Mean Frequency','L2RS Mean Damage','L2IB Mean Frequency', 'L2IB Mean Damage','L2FS Mean Frequency','L2FS Mean Damage', 'L2LTS Mean Frequency','L2LTS Mean Damage','Location','eastoutside')
                % 					legend('L2RS Mean Frequency', 'L2IB Mean Frequency', 'L2FS Mean Frequency', 'L2LTS Mean Frequency','Location','eastoutside')
            elseif(type == t.E4)
                ColorFrequency = VideoColors(1,:);
                subplot(2,2,2);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I4)
                ColorFrequency = VideoColors(5,:);
                subplot(2,2,2);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I4L)
                ColorFrequency = VideoColors(10,:);
                subplot(2,2,2);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
                legend('L4RS Mean Frequency','L4RS Mean Damage','L4FS Mean Frequency','L4FS Mean Damage', 'L4LTS Mean Frequency','L4LTS Mean Damage','Location','eastoutside')
                % 					legend('L4RS Mean Frequency', 'L4FS Mean Frequency', 'L4LTS Mean Frequency','Location','eastoutside')
            elseif(type == t.E5R)
                ColorFrequency = VideoColors(1,:);
                subplot(2,2,3);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.E5B)
                ColorFrequency = VideoColors(3,:);
                subplot(2,2,3);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I5)
                ColorFrequency = VideoColors(5,:);
                subplot(2,2,3);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I5L)
                ColorFrequency = VideoColors(10,:);
                subplot(2,2,3);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
                legend('L5IB Mean Frequency','L5IB Mean Damage','L5RS Mean Frequency', 'L5RS Mean Damage','L5FS Mean Frequency','L5FS Mean Damage', 'L5LTS Mean Frequency','L5LTS Mean Damage','Location','eastoutside')
                % 					legend('L5IB Mean Frequency', 'L5RS Mean Frequency', 'L5FS Mean Frequency', 'L5LTS Mean Frequency','Location','eastoutside')
            elseif(type == t.E6)
                ColorFrequency = VideoColors(1,:);
                subplot(2,2,4);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I6)
                ColorFrequency = VideoColors(5,:);
                subplot(2,2,4);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
            elseif(type == t.I6L)
                ColorFrequency = VideoColors(10,:);
                subplot(2,2,4);
                hold on;
                plot(0:final/(stopat-1):final, SummaryFrequencies(type+column*40,1:stopat)/max(max(SummaryFrequencies)),'Color',2*ColorFrequency/256,'LineWidth',2);
                plot(0:final/(stopat-1):final, SummaryDamage(type+column*40,1:stopat)/max(SummaryDamage(type+column*40,:)),'--','Color',1.5*ColorFrequency/256,'LineWidth',1);
                legend('L6RS Mean Frequency','L6RS Mean Damage','L6FS Mean Frequency','L6FS Mean Damage', 'L6LTS Mean Frequency','L6LTS Mean Damage','Location','eastoutside')
                % 					legend('L6RS Mean Frequency', 'L6FS Mean Frequency', 'L6LTS Mean Frequency', 'Location','eastoutside')
            end
            set(gca,'FontSize',FontSizeAll)
            %title(['Column ' num2str(column+1)],'FontSize',FontSizeAll)
            xlabel('time','FontSize',FontSizeAll)
            ylabel('Normalized Firing Frequencies','FontSize',FontSizeAll-1)
            ylim([0 1])
            xlim([0 final])
        end
    end
    hold off
    set(gcf, 'Color', 'w');
    if(savepdf)
        export_fig([CurrentSaveDirectory 'DamageFrequencies' num2str(column+1)], '-pdf', '-painters', '-a1', '-q101')
    end
end


end