function PlotClusteredVsDistributedCluster( CurrentLoadDirectory, CurrentSaveDirectory, savepdf )
load([CurrentLoadDirectory 'Everything.mat'], 'VideoConcentrations', 'CellColumns', 'NumColumns', 'DijkstraAll');
%What frame should the video stop at
VideoStopAt = 0;
for frame = size(VideoConcentrations,2):-1:1
    if(any(VideoConcentrations(:,frame) > 0))
        VideoStopAt = frame;
        break;
    end
end
VideoConcentrations = VideoConcentrations/max(max(VideoConcentrations));
	
	Score1 = zeros(1,VideoStopAt);
	Score2 = zeros(1,VideoStopAt); 
	Score3 = zeros(1,VideoStopAt); 
	Score4 = zeros(1,VideoStopAt); 
	
	Maxdistance = max(max(DijkstraAll));
	Ctotal = zeros(1,VideoStopAt);
	DijkstraAll = DijkstraAll/Maxdistance;
	MedianDijkstra = median(DijkstraAll(:));
	for frame = 1:VideoStopAt
		C = VideoConcentrations(:,frame);
		Call = C*C';
		for i = 1:size(Call,1)
			Call(i,i) = 0;
		end
		Ctotal(frame) = sum(sum(Call));
		Score1(frame) = sum(sum((DijkstraAll-MedianDijkstra) .* Call))/1410/1410;
		Score2(frame) = sum(sum((DijkstraAll-0)              .* Call))/1410/1410;
		if(Ctotal(frame) > 0)
			Score3(frame) = 1410*1410*Score1(frame)/Ctotal(frame);
			Score4(frame) = 1410*1410*Score2(frame)/Ctotal(frame);
		end
	end
	figure; subplot(4,1,1); plot(Score1); subplot(4,1,2); plot(Score2);
	subplot(4,1,3); plot(Score3); subplot(4,1,4); plot(Score4);

	ScoreMaxClustDistr(CurrentExperiment,1) = max(Score1);
	ScoreMeanClustDistr(CurrentExperiment,1) = mean(Score1);
	ScoreClustDistr{CurrentExperiment,1} = Score1;
	ScoreMaxClustDistr(CurrentExperiment,2) = max(Score2);
	ScoreMeanClustDistr(CurrentExperiment,2) = mean(Score2);
	ScoreClustDistr{CurrentExperiment,2} = Score2;
	ScoreMaxClustDistr(CurrentExperiment,3) = max(Score3);
	ScoreMeanClustDistr(CurrentExperiment,3) = mean(Score3);
	ScoreClustDistr{CurrentExperiment,3} = Score3;
	ScoreMaxClustDistr(CurrentExperiment,4) = max(Score4);
	ScoreMeanClustDistr(CurrentExperiment,4) = mean(Score4);
	ScoreClustDistr{CurrentExperiment,4} = Score4;
	
	width = 30;
	height = 15;
	DistancesHistFigure = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
		'PaperUnits','centimeters',...
		'PaperSize',[width height],...
		'PaperPositionMode','auto',...
		'InvertHardcopy', 'on',...
		'Renderer','painters'...
		);
	plot(ScoreClustDistr{CurrentExperiment,3})	
	set(gca,'FontSize',FontSizeAll)
	title(['If high value then high distributedness ' num2str(mean(ScoreClustDistr{CurrentExperiment,3}))],'FontSize',FontSizeAll)
	xlabel('Time','FontSize',FontSizeAll)
	ylabel('Distributedness value','FontSize',FontSizeAll)
	if(savepdf)
		set(gcf, 'Color', 'w');
		export_fig([CurrentSaveDirectory 'Distributedness.pdf'], '-pdf', '-painters', '-a1', '-q101')
	end
	
	close all;
end
figure; plot(ScoreMaxClustDistr);
save([Save_Directory 'ScoreMaxClustDistr.mat'], 'ScoreMaxClustDistr');
save([Save_Directory 'ScoreMeanClustDistr.mat'], 'ScoreMeanClustDistr');
save([Save_Directory 'ScoreClustDistr.mat'], 'ScoreClustDistr');
end



% load([Save_Directory 'ScoreMaxClustDistr.mat']);
% load([Save_Directory 'ScoreMeanClustDistr.mat']);
% load([Save_Directory 'ScoreClustDistr.mat']);
% 
% figure; subplot(4,1,1); plot(ScoreMaxClustDistr(:,1)); subplot(4,1,2); plot(ScoreMaxClustDistr(:,2));
% 	subplot(4,1,3); plot(ScoreMaxClustDistr(:,3)); subplot(4,1,4); plot(ScoreMaxClustDistr(:,4));
% figure; subplot(4,1,1); plot(ScoreMeanClustDistr(:,1)); subplot(4,1,2); plot(ScoreMeanClustDistr(:,2));
% 	subplot(4,1,3); plot(ScoreMeanClustDistr(:,3),'-*'); subplot(4,1,4); plot(ScoreMeanClustDistr(:,4));
	
% 
% close all;
% figure;
% k = 37;
% for i = 1:4
% 	for j = 1:numel(ScoreClustDistr{k,i})
% 		if(ScoreClustDistr{k,i}(j)>0)
% 			break;
% 		end
% 	end
% 	j=1;
% 	subplot(4,1,i); plot(ScoreClustDistr{k,i}(j:end));
% end
	

	

% close all;
% for c = 1:4
% 	for k = 2
% 	figure;
% 	for i = 0:8
% 		for j = 1:numel(ScoreClustDistr{16*i+k,c})
% 			if(ScoreClustDistr{16*i+k,c}(j)>0)
% 				break;
% 			end
% 		end
% 		 subplot(3,3,i+1); plot(ScoreClustDistr{16*i+k,c}(j:end));
% 	end
% 	
% 	end
% end
% 
% figure
% for c = 1:4
% 	for k = 2
% 	for i = 0:8
% 		for j = 1:numel(ScoreClustDistr{16*i+k,c})
% 			if(ScoreClustDistr{16*i+k,c}(j)>0)
% 				break;
% 			end
% 		end
% 		j = 1;
% 		if(i == 0)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'g'); hold on;
% 		elseif(i == 1)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'g--'); hold on;
% 		elseif(i == 2)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'g:'); hold on;
% 		elseif(i == 3)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'y'); hold on;
% 		elseif(i == 4)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'y--'); hold on;
% 		elseif(i == 5)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'y:'); hold on;
% 		elseif(i == 6)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'r'); hold on;
% 		elseif(i == 7)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'r--'); hold on;
% 		elseif(i == 8)
% 			subplot(4,1,c); hold on; plot(ScoreClustDistr{16*i+k,c}(j:end), 'r:'); hold on;
% 		end
% 	end
% 	
% 	end
% end	