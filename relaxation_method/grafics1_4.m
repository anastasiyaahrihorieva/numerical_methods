if exist('norms.txt', 'file')
    data = load('norms.txt');  
    
    figure;
     xlabel('norm');
     ylabel('eps');
    loglog(data(:,3), data(:,1), 'red'); %n_n
     grid on;
    hold on; 
    loglog(data(:,3), data(:,2), 'blue'); 
    grid on;
    hold on; 

else
    error('norms.txt не найден');
end

if exist('iter.txt', 'file')
    iter = load('iter.txt');  
det = load('det_all.txt'); 

    figure;
     xlabel('det');
     ylabel('iter');
    semilogx(det(:,1), iter(:,1), 'red'); 
     grid on;
    hold on; 
else
    error('iter.txt не найден');
end