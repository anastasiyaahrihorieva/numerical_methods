det_all = zeros(1, 10); 
for i = 1:10
    det_all(i) = 10.^(-i+1);
end
figure
data = load('norms_scalar.txt');
data_no_norm = load('norms_scalar_NO_NORM.txt');

loglog(data(:,1), data(:,2), 'red'); %норма ф ерр
hold on;
loglog(data(:,1), data(:,4), 'k'); %невязка
hold on;
loglog(data_no_norm(:,1), data_no_norm(:,2), 'blue');
hold on;
loglog(data_no_norm(:,1), data_no_norm(:,4), 'green');

hold on;

grid on;

xlabel('точность');
ylabel('фактическая ошибка/норма невязки');
legend('факт ошибка', 'невязка', 'факт ошибка без норм-ки', 'невязка без норм-ки');

figure;
semilogx(data(:,1), data(:,3), 'green');
hold on;
semilogx(data_no_norm(:,1), data_no_norm(:,3), 'k');
grid on;

xlabel('точность');
ylabel('итерации');
legend('итер-и', 'итер-и без норм-ки', 'Location', 'northeast');