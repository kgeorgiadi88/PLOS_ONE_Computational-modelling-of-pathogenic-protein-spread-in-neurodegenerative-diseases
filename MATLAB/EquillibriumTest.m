close all;SpawnNT = 0;SpawnMT = 0;MisfoldNT = 0;MisfoldMT = 0;ClearNT = 0;ClearMT = 0;iteration = 0; SpawnMinusClearT =0; SpawnMinusClearMeanT = 0;
PlotAt = .04;

Cn                = 0.005;    Cm                = 0.005;
SpawnNFactor      = 0.0001;    SpawnMFactor      = 0.00000000001;

MisfoldFactor     = 1;%0.01565;


%ClearanceNMinimum = 0.1e-4;  ClearanceMMinimum = 0.1e-4;
ClearanceNFactor  = SpawnNFactor;    ClearanceMFactor  = SpawnMFactor;
%ClearanceNMaximum = 1.1e-4;  ClearanceMMaximum = 0.22e-4;
ClearNNormal      = Cn;      ClearMNormal      = Cm;
%ClearNMax         = 0.051;   ClearMMax         = 0.011;

while(1)
	iteration = iteration + 1;
	%how much will spawn
	SpawnN = SpawnNFactor + (SpawnNFactor/10)*randn(1);
	SpawnM = SpawnMFactor + (SpawnMFactor/10)*randn(1);
	%Add spawned
	Cn = Cn + SpawnN;
	Cm = Cm + SpawnM;
	
	%How much will misfold
	Misfolded = Cn*Cm*MisfoldFactor;
	Cn = Cn - Misfolded;
	Cm = Cm + Misfolded;
	
	%How much will get cleared
	ClearN = log(1+(exp(1)-1)*Cn/ClearNNormal)*ClearanceNFactor;
	ClearN = ClearN + (ClearN/10)*randn(1);
	Cn = Cn - ClearN;
	ClearM = log(1+(exp(1)-1)*Cm/ClearMNormal)*ClearanceMFactor;
	ClearM = ClearM + (ClearM/10)*randn(1);
	Cm = Cm - ClearM;
	
	if(Cn < 0)
		Cn = 0;
	end
	if(Cm < 0)
		Cm = 0;
	end
	ClearNT(iteration) = Cn;
	ClearMT(iteration) = Cm;
	SpawnMinusClearT(iteration) = SpawnN+SpawnM-ClearN-ClearM;
	if(iteration < 25000)
		SpawnMinusClearMeanT(iteration) = 0;
	elseif(iteration == 25000)
		SpawnMinusClearMeanT(iteration) = mean(SpawnMinusClearT);
	else
		SpawnMinusClearMeanT(iteration) = SpawnMinusClearMeanT(iteration-1)+(-SpawnMinusClearT(iteration-25000)+SpawnMinusClearT(iteration))/25000;
	end
	if(mod(iteration,5000)==0)
		figure(1); ylim([0 PlotAt]);plot(ClearNT,'b'); hold on;ylim([0 PlotAt]);plot(ClearMT,'r'); hold off;ylim([0 PlotAt]);
		legend('Normal concentration', 'Pathogenic concentration');
		xlabel('Timestep');
		ylabel('Protein Concentration');
		%figure(2); %plot(SpawnMinusClearT);hold on; 
		%plot(zeros(numel(SpawnMinusClearT),1),'r');hold on; plot(SpawnMinusClearMeanT,'g');set(gcf, 'Position', [700 0 700 500]);hold off;
	end
	
	if(Cm+Cn > PlotAt)
		break;
	end
end
ClearNT1 = ClearNT;
ClearMT1 = ClearMT;

SpawnNT = 0;SpawnMT = 0;MisfoldNT = 0;MisfoldMT = 0;ClearNT = 0;ClearMT = 0;iteration = 0; SpawnMinusClearT =0; SpawnMinusClearMeanT = 0;
PlotAt = .4;

Cn                = 0.05;    Cm                = 0.01;
SpawnNFactor      = 4e-4;    SpawnMFactor      = 0.8e-4;

MisfoldFactor     = 0.0624;%0.01565;


%ClearanceNMinimum = 0.1e-4;  ClearanceMMinimum = 0.1e-4;
ClearanceNFactor  = SpawnNFactor;    ClearanceMFactor  = SpawnMFactor;
%ClearanceNMaximum = 1.1e-4;  ClearanceMMaximum = 0.22e-4;
ClearNNormal      = Cn;      ClearMNormal      = Cm;
%ClearNMax         = 0.051;   ClearMMax         = 0.011;

while(1)
	iteration = iteration + 1;
	%how much will spawn
	SpawnN = SpawnNFactor + (SpawnNFactor/10)*randn(1);
	SpawnM = SpawnMFactor + (SpawnMFactor/10)*randn(1);
	%Add spawned
	Cn = Cn + SpawnN;
	Cm = Cm + SpawnM;
	
	%How much will misfold
	Misfolded = Cn*Cm*MisfoldFactor;
	Cn = Cn - Misfolded;
	Cm = Cm + Misfolded;
	
	%How much will get cleared
	ClearN = log(1+(exp(1)-1)*Cn/ClearNNormal)*ClearanceNFactor;
	ClearN = ClearN + (ClearN/10)*randn(1);
	Cn = Cn - ClearN;
	ClearM = log(1+(exp(1)-1)*Cm/ClearMNormal)*ClearanceMFactor;
	ClearM = ClearM + (ClearM/10)*randn(1);
	Cm = Cm - ClearM;
	
	if(Cn < 0)
		Cn = 0;
	end
	if(Cm < 0)
		Cm = 0;
	end
	ClearNT(iteration) = Cn;
	ClearMT(iteration) = Cm;
	SpawnMinusClearT(iteration) = SpawnN+SpawnM-ClearN-ClearM;
	if(iteration < 25000)
		SpawnMinusClearMeanT(iteration) = 0;
	elseif(iteration == 25000)
		SpawnMinusClearMeanT(iteration) = mean(SpawnMinusClearT);
	else
		SpawnMinusClearMeanT(iteration) = SpawnMinusClearMeanT(iteration-1)+(-SpawnMinusClearT(iteration-25000)+SpawnMinusClearT(iteration))/25000;
	end
	if(mod(iteration,5000)==0)
		figure(1); ylim([0 PlotAt]);plot(ClearNT,'b'); hold on;ylim([0 PlotAt]);plot(ClearMT,'r'); hold off;ylim([0 PlotAt]);
		legend('Normal concentration', 'Pathogenic concentration');
		xlabel('Timestep');
		ylabel('Protein Concentration');
		%figure(2); %plot(SpawnMinusClearT);hold on; 
		%plot(zeros(numel(SpawnMinusClearT),1),'r');hold on; plot(SpawnMinusClearMeanT,'g');set(gcf, 'Position', [700 0 700 500]);hold off;
	end
	
	if(Cm+Cn > PlotAt)
		break;
	end
end
ClearNT2 = ClearNT;
ClearMT2 = ClearMT;

SpawnNT = 0;SpawnMT = 0;MisfoldNT = 0;MisfoldMT = 0;ClearNT = 0;ClearMT = 0;iteration = 0; SpawnMinusClearT =0; SpawnMinusClearMeanT = 0;
PlotAt = .4;

Cn                = 0.05;    Cm                = 0.01;
SpawnNFactor      = 4e-4;    SpawnMFactor      = 0.8e-4;

MisfoldFactor     = 0.0622;%0.01565;


%ClearanceNMinimum = 0.1e-4;  ClearanceMMinimum = 0.1e-4;
ClearanceNFactor  = SpawnNFactor;    ClearanceMFactor  = SpawnMFactor;
%ClearanceNMaximum = 1.1e-4;  ClearanceMMaximum = 0.22e-4;
ClearNNormal      = Cn;      ClearMNormal      = Cm;
%ClearNMax         = 0.051;   ClearMMax         = 0.011;

while(1)
	iteration = iteration + 1;
	%how much will spawn
	SpawnN = SpawnNFactor + (SpawnNFactor/10)*randn(1);
	SpawnM = SpawnMFactor + (SpawnMFactor/10)*randn(1);
	%Add spawned
	Cn = Cn + SpawnN;
	Cm = Cm + SpawnM;
	
	%How much will misfold
	Misfolded = Cn*Cm*MisfoldFactor;
	Cn = Cn - Misfolded;
	Cm = Cm + Misfolded;
	
	%How much will get cleared
	ClearN = log(1+(exp(1)-1)*Cn/ClearNNormal)*ClearanceNFactor;
	ClearN = ClearN + (ClearN/10)*randn(1);
	Cn = Cn - ClearN;
	ClearM = log(1+(exp(1)-1)*Cm/ClearMNormal)*ClearanceMFactor;
	ClearM = ClearM + (ClearM/10)*randn(1);
	Cm = Cm - ClearM;
	
	if(Cn < 0)
		Cn = 0;
	end
	if(Cm < 0)
		Cm = 0;
	end
	ClearNT(iteration) = Cn;
	ClearMT(iteration) = Cm;
	SpawnMinusClearT(iteration) = SpawnN+SpawnM-ClearN-ClearM;
	if(iteration < 25000)
		SpawnMinusClearMeanT(iteration) = 0;
	elseif(iteration == 25000)
		SpawnMinusClearMeanT(iteration) = mean(SpawnMinusClearT);
	else
		SpawnMinusClearMeanT(iteration) = SpawnMinusClearMeanT(iteration-1)+(-SpawnMinusClearT(iteration-25000)+SpawnMinusClearT(iteration))/25000;
	end
	if(mod(iteration,5000)==0)
		figure(1); ylim([0 PlotAt]);plot(ClearNT,'b'); hold on;ylim([0 PlotAt]);plot(ClearMT,'r'); hold off;ylim([0 PlotAt]);
		legend('Normal concentration', 'Pathogenic concentration');
		xlabel('Timestep');
		ylabel('Protein Concentration');
		%figure(2); %plot(SpawnMinusClearT);hold on; 
		%plot(zeros(numel(SpawnMinusClearT),1),'r');hold on; plot(SpawnMinusClearMeanT,'g');set(gcf, 'Position', [700 0 700 500]);hold off;
	end
	
	if(Cm+Cn > PlotAt)
		break;
	end
end
ClearNT3 = ClearNT;
ClearMT3 = ClearMT;





FontSizeAll = 28;
width = 60;
height = 20;
h2 = figure('visible','on','Units','centimeters', 'Position',[0 0 width height],...
		'PaperUnits','centimeters',...
		'PaperSize',[width height],...
		'PaperPositionMode','auto',...
		'InvertHardcopy', 'on',...
		'Renderer','painters'...
		);


subplot(1,3,1);ylim([0 PlotAt]);plot(ClearNT1,'b', 'LineWidth', 2); hold on;plot(ClearMT1, 'r', 'LineWidth', 2); hold off;ylim([0 PlotAt]);
hlegend = legend('Normal protein', 'Pathogenic protein');
set(hlegend,'FontSize',FontSizeAll);
xlabel('Timestep', 'fontsize', FontSizeAll);
ylabel('Protein Concentration', 'fontsize', FontSizeAll);
set(gca,'FontSize',FontSizeAll)
set(gcf, 'Color', 'w');
subplot(1,3,2);ylim([0 PlotAt]);plot(ClearNT2,'b', 'LineWidth', 2); hold on;plot(ClearMT2,'r', 'LineWidth', 2); hold off;ylim([0 PlotAt]);
hlegend = legend('Normal protein', 'Pathogenic protein');
set(hlegend,'FontSize',FontSizeAll);
xlabel('Timestep', 'fontsize', FontSizeAll);
ylabel('Protein Concentration', 'fontsize', FontSizeAll);
set(gca,'FontSize',FontSizeAll)
set(gcf, 'Color', 'w');
subplot(1,3,3);ylim([0 PlotAt]);plot(ClearNT3,'b', 'LineWidth', 2); hold on;plot(ClearMT3,'r', 'LineWidth', 2); hold off;ylim([0 PlotAt]);
hlegend = legend('Normal protein', 'Pathogenic protein');
set(hlegend,'FontSize',FontSizeAll);
xlabel('Timestep', 'fontsize', FontSizeAll);
ylabel('Protein Concentration', 'fontsize', FontSizeAll);
set(gca,'FontSize',FontSizeAll)
set(gcf, 'Color', 'w'); 
export_fig('EquilibriumSimulation', '-pdf', '-painters', '-a1', '-q101')













