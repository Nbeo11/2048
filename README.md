# Hướng dẫn chơi
2048 chơi trên một bảng vuông 4×4. 
Mỗi lần di chuyển là một lượt, người chơi sử dụng các phím mũi tên và các khối vuông sẽ trượt theo một trong bốn hướng tương ứng (lên, xuống, trái, phải). 
Mỗi lượt có một khối có giá trị 2 hoặc 4 sẽ xuất hiện ngẫu nhiên ở một ô trống trên bảng. 
Các khối vuông trượt theo hướng chỉ định cho đến khi chạm đến biên của lưới hoặc chạm vào khối vuông khác. 
Nếu hai khối vuông có cùng giá trị chạm vào nhau, chúng sẽ kết hợp lại thành một khối vuông có giá trị bằng tổng giá trị hai khối vuông đó (giá trị gấp đôi). 
Khối vuông kết quả không thể kết hợp với khối vuông khác một lần nữa trong một lượt di chuyển. 
Bảng điểm ở góc trên bên trái cho biết điểm của người chơi. Ban đầu điểm bằng 0. Khi hai khối vuông kết hợp thì người chơi sẽ tăng điểm là giá trị khối vuông mới.  
Khi không còn nước đi hợp lệ (không còn ô trống và các ô kề nhau đều khác giá trị) thì trò chơi kết thúc.
Ấn phím R hoặc nháy chuột vào biểu tưởng quay lại trên màn hình để chơi lại.
