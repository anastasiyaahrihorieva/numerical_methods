condA = logspace(1, 10, 10); % 10 значений от 10 до 10^10

if exist('norms.txt', 'file')
    data = load('norms.txt');  
    figure
    loglog(condA, data(:, 1), 'red'); 
    grid on;
    hold on; 
    loglog(condA, data(:, 2), 'blue'); 
    xlabel('condA');
    ylabel('normX - red, normN - blue'); % Подпись по оси Y
    hold off; 
else
    error('NORM.txt не найден');
end


if exist('errors.txt', 'file')
    data = load('errors.txt');  
    
    % Сортировка данных по возрастанию значений в первой колонке
    [x_sorted, sort_idx] = sort(data(:, 1)); % Сортируем первую колонку
    y_sorted = data(sort_idx, 2); % Переупорядочиваем вторую колонку по индексам сортировки

    % Построение графика
    figure;
    loglog(x_sorted, y_sorted, 'red'); 
    grid on;
    hold on; 

else
    error('errors.txt не найден');
end