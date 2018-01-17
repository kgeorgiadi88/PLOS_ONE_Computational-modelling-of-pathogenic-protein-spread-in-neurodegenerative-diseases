function PlotConvergence( AllNumbers, Load_Directories, Save_Directory, savepdf, Convergence_Threshold )
FontSizeAll = 18;

for experiment = 1:prod(AllNumbers)
	close all;
	CurrentDirectory = Load_Directories{experiment};
	SimulationFinished = dlmread([CurrentDirectory 'Finished.dat']);
    if(SimulationFinished ~= 1)
        fprintf('\n\n!!!!!\nREAD ERROR. Simulation never finished!!!!!!!\n!!!!!\n\n');
        continue;
        %break;
    end
    OrderIndices = dlmread([CurrentDirectory 'AtrophyOrderIndices.dat']);
	EventSequenceVectors(:,experiment) = OrderIndices'+1;
end

NumElements = size(EventSequenceVectors,1);
ConvergenceMinMatrix = zeros(prod(AllNumbers));
ConvergenceMeanMatrix = zeros(prod(AllNumbers));
for experiment1 = 1:prod(AllNumbers)
	for experiment2 = (experiment1+1):prod(AllNumbers)
		if(EventSequenceVectors(1,experiment1) == 0 || EventSequenceVectors(1,experiment2) == 0)
			ConvergenceVector = zeros(NumElements,1);
			ConvergenceVector2 = zeros(NumElements,1);
		else
			A1 = false(NumElements,1);
			A2 = false(NumElements,1);
			SumVar = 0;
			for i = 1:NumElements
				A1(EventSequenceVectors(i,experiment1)) = true;
				SumVar = SumVar + A2(EventSequenceVectors(i,experiment1));
				A2(EventSequenceVectors(i,experiment2)) = true;
				SumVar = SumVar + A1(EventSequenceVectors(i,experiment2));
				ConvergenceVector(i,1) = SumVar/i;
				ConvergenceVector2(i,1) = SumVar/NumElements;
			end
		end
		
		
		%Min is best
		MovingMin = zeros(NumElements,1);
		minval = 10;
		for i = NumElements:-1:1
			if(ConvergenceVector(i) < minval)
				minval = ConvergenceVector(i);
			end
			MovingMin(i) = minval;
		end
		for i = 1:NumElements
			if(MovingMin(i) >= Convergence_Threshold)
				EarliestConvergence = i;
				break;
			end
		end
		ConvergenceMinMatrix(experiment1, experiment2) = EarliestConvergence;
		ConvergenceMinMatrix(experiment2, experiment1) = EarliestConvergence;
		
		%Mean is best
		MovingMean = zeros(NumElements,1);
		meanval = 0;
		for i = 1:NumElements
			meanval = ((i-1)*meanval + ConvergenceVector(end-i+1))/i;
			MovingMean(end-i+1) = meanval;
		end
		Temp = find(MovingMean < Convergence_Threshold);
		if(isempty(Temp))
			EarliestConvergence = 1;
		else
			EarliestConvergence = Temp(end);
		end
		ConvergenceMeanMatrix(experiment1, experiment2) = EarliestConvergence;
		ConvergenceMeanMatrix(experiment2, experiment1) = EarliestConvergence;
		
		SqrtDiff = sqrt(sum((ConvergenceVector2-((1:NumElements)/NumElements)').^2));
		x = (1:NumElements)';
		y = ConvergenceVector2;
		p = polyfit(x,y,1);
		yfit = polyval(p,x);
		yresid = y - yfit;
		SSresid = sum(yresid.^2);
		SStotal = (length(y)-1) * var(y);
		rsq = 1 - SSresid/SStotal;
		ConvergenceR2Matrix(experiment1, experiment2) = SqrtDiff;
		ConvergenceR2Matrix(experiment2, experiment1) = SqrtDiff;
		
		ConvergenceRSQMatrix(experiment1, experiment2) = rsq;
		ConvergenceRSQMatrix(experiment2, experiment1) = rsq;
	end
end

ConvergenceMinMatrix = ConvergenceMinMatrix/NumElements;
ConvergenceMeanMatrix = ConvergenceMeanMatrix/NumElements;

dlmwrite([Save_Directory 'ConvergenceMin.dat'], ConvergenceMinMatrix, ' ');

close all;
width = 30;
height = 30;
h2 = figure('visible','on','Units','centimeters', 'Position',[0 0 width height],...
	'PaperUnits','centimeters',...
	'PaperSize',[width height],...
	'PaperPositionMode','auto',...
	'InvertHardcopy', 'on',...
	'Renderer','painters'...
	);
imagesc(ConvergenceMinMatrix);
% for i = 0:16:prod(AllNumbers); line(xlim+[-7 0],[1,1]*i + 0.5,'color','k','LineWidth',2,'Clipping','off');  end
% for i = 0:16:prod(AllNumbers); line([1,1]*i + 0.5,ylim+[0 5],'color','k','LineWidth',2,'Clipping','off');  end
% for i = 0:3*16:prod(AllNumbers); line(xlim+[-12 0],[1,1]*i + 0.5,'color','k','LineWidth',4,'Clipping','off');  end
% for i = 0:3*16:prod(AllNumbers); line([1,1]*i + 0.5,ylim+[0 10],'color','k','LineWidth',4,'Clipping','off');  end
set(gca,'FontSize',FontSizeAll)
title(['Convergence measured by the earliest timestep that the dice score remained >' num2str(Convergence_Threshold)],'FontSize',FontSizeAll)

% i = prod(AllNumbers)+5; line(xlim+[-0 0],[1,1]*i + 0.5,'color','k','LineWidth',2,'Clipping','off'); 
% i = -7; line([1,1]*i + 0.5,ylim+[0 0],'color','k','LineWidth',2,'Clipping','off');
% 
% t0 = text(-4,15+16*0,'f_{inter}=1','FontSize',14);
% t1 = text(-4,15+16*1,'f_{inter}=10','FontSize',14);
% t2 = text(-4,15+16*2,'f_{inter}=100','FontSize',14);
% t3 = text(-4,15+16*3,'f_{inter}=1','FontSize',14);
% t4 = text(-4,15+16*4,'f_{inter}=10','FontSize',14);
% t5 = text(-4,15+16*5,'f_{inter}=100','FontSize',14);
% t6 = text(-4,15+16*6,'f_{inter}=1','FontSize',14);
% t7 = text(-4,15+16*7,'f_{inter}=10','FontSize',14);
% t8 = text(-4,15+16*8,'f_{inter}=100','FontSize',14);
% 
% ts1 = text(-10,15+16*1,'{\sigma}_z=50','FontSize',14);
% ts4 = text(-10,15+16*4,'{\sigma}_z=100','FontSize',14);
% ts7 = text(-10,15+16*7,'{\sigma}_z=1000','FontSize',14);
% 
% set(t0, 'rotation', 90)
% set(t1, 'rotation', 90)
% set(t2, 'rotation', 90)
% set(t3, 'rotation', 90)
% set(t4, 'rotation', 90)
% set(t5, 'rotation', 90)
% set(t6, 'rotation', 90)
% set(t7, 'rotation', 90)
% set(t8, 'rotation', 90)
% set(ts1, 'rotation', 90)
% set(ts4, 'rotation', 90)
% set(ts7, 'rotation', 90)
% 
% 
% text(2+16*0,147,'f_{inter}=1','FontSize',14)
% text(2+16*1,147,'f_{inter}=10','FontSize',14)
% text(2+16*2,147,'f_{inter}=100','FontSize',14)
% text(2+16*3,147,'f_{inter}=1','FontSize',14)
% text(2+16*4,147,'f_{inter}=10','FontSize',14)
% text(2+16*5,147,'f_{inter}=100','FontSize',14)
% text(2+16*6,147,'f_{inter}=1','FontSize',14)
% text(2+16*7,147,'f_{inter}=10','FontSize',14)
% text(2+16*8,147,'f_{inter}=100','FontSize',14)
% 
% text(2+16*1,152,'{\sigma}_z=50','FontSize',14)
% text(2+16*4,152,'{\sigma}_z=100','FontSize',14)
% text(2+16*7,152,'{\sigma}_z=1000','FontSize',14)

%xlabel({'';'';'Simulation ID S.x'}, 'FontSize', FontSizeAll);
%ylabel({'Simulation ID S.y';'';'';''}, 'FontSize', FontSizeAll);
set(gca, 'CLim', [0, 1]);
colorbar;
set(gca,'visible','off');
set(gcf, 'Color', 'w');
title(['Convergence measured by the earliest timestep that the dice score remained >' num2str(Convergence_Threshold)],'FontSize',FontSizeAll)
if(savepdf)
	export_fig([Save_Directory 'ConvergenceMin' num2str(uint32(Convergence_Threshold*100))], '-pdf', '-png', '-painters', '-a1', '-q101')
end










dlmwrite([Save_Directory 'ConvergenceMean.dat'], ConvergenceMeanMatrix, ' ');
width = 30;
height = 30;
h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
	'PaperUnits','centimeters',...
	'PaperSize',[width height],...
	'PaperPositionMode','auto',...
	'InvertHardcopy', 'on',...
	'Renderer','painters'...
	);
imagesc(ConvergenceMeanMatrix);
% for i = 16:16:prod(AllNumbers); line(xlim,[1,1]*i + 0.5,'color','k','LineWidth',2);  end
% for i = 16:16:prod(AllNumbers); line([1,1]*i + 0.5,ylim,'color','k','LineWidth',2);  end
% for i = 3*16:3*16:prod(AllNumbers); line(xlim,[1,1]*i + 0.5,'color','k','LineWidth',6);  end
% for i = 3*16:3*16:prod(AllNumbers); line([1,1]*i + 0.5,ylim,'color','k','LineWidth',6);  end
set(gca,'FontSize',FontSizeAll)
title(['Convergence measured by the earliest timestep that the mean dice score remained >' num2str(Convergence_Threshold)],'FontSize',FontSizeAll)
xlabel('Simulation ID x','FontSize',FontSizeAll)
ylabel('Simulation ID y','FontSize',FontSizeAll)
set(gca, 'CLim', [0, 1]);
colorbar
set(gcf, 'Color', 'w');
if(savepdf)
	export_fig([Save_Directory 'ConvergenceMean' num2str(uint32(Convergence_Threshold*100))], '-pdf', '-png', '-painters', '-a1', '-q101')
end

dlmwrite([Save_Directory 'ConvergenceDistanceStraight.dat'], ConvergenceR2Matrix, ' ');
width = 30;
height = 30;
h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
	'PaperUnits','centimeters',...
	'PaperSize',[width height],...
	'PaperPositionMode','auto',...
	'InvertHardcopy', 'on',...
	'Renderer','painters'...
	);
imagesc(ConvergenceR2Matrix);
% for i = 16:16:prod(AllNumbers); line(xlim,[1,1]*i + 0.5,'color','k','LineWidth',2);  end
% for i = 16:16:prod(AllNumbers); line([1,1]*i + 0.5,ylim,'color','k','LineWidth',2);  end
% for i = 3*16:3*16:prod(AllNumbers); line(xlim,[1,1]*i + 0.5,'color','k','LineWidth',6);  end
% for i = 3*16:3*16:prod(AllNumbers); line([1,1]*i + 0.5,ylim,'color','k','LineWidth',6);  end
set(gca,'FontSize',FontSizeAll)
title('Convergence measured by the distance of the dice score to a straight line','FontSize',FontSizeAll)
xlabel('Simulation ID x','FontSize',FontSizeAll)
ylabel('Simulation ID y','FontSize',FontSizeAll)
%set(gca, 'CLim', [0, 1]);
colorbar
set(gcf, 'Color', 'w');
if(savepdf)
	export_fig([Save_Directory 'ConvergenceDistanceStraight'], '-pdf', '-png', '-painters', '-a1', '-q101')
end

dlmwrite([Save_Directory 'ConvergenceRSQMatrix.dat'], ConvergenceRSQMatrix, ' ');
width = 30;
height = 30;
h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
	'PaperUnits','centimeters',...
	'PaperSize',[width height],...
	'PaperPositionMode','auto',...
	'InvertHardcopy', 'on',...
	'Renderer','painters'...
	);
imagesc(ConvergenceRSQMatrix);
% for i = 16:16:prod(AllNumbers); line(xlim,[1,1]*i + 0.5,'color','k','LineWidth',2);  end
% for i = 16:16:prod(AllNumbers); line([1,1]*i + 0.5,ylim,'color','k','LineWidth',2);  end
% for i = 3*16:3*16:prod(AllNumbers); line(xlim,[1,1]*i + 0.5,'color','k','LineWidth',6);  end
% for i = 3*16:3*16:prod(AllNumbers); line([1,1]*i + 0.5,ylim,'color','k','LineWidth',6);  end
set(gca,'FontSize',FontSizeAll)
title('Convergence measured by R^2 of the dice score','FontSize',FontSizeAll)
xlabel('Simulation ID x','FontSize',FontSizeAll)
ylabel('Simulation ID y','FontSize',FontSizeAll)
%set(gca, 'CLim', [0, 1]);
colorbar
set(gcf, 'Color', 'w');
if(savepdf)
	export_fig([Save_Directory 'ConvergenceRSQMatrix'], '-pdf', '-png', '-painters', '-a1', '-q101')
end

%close all;
end