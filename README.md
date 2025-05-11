# 🎮 Fruit Cut - SDL2 Game Project 🍉🔪

# Họ và tên:Phạm Thế Hùng

# Mã sinh viên: **24022825**

# Repository GitHub: [https://github.com/pHung526/btl-game](https://github.com/pHung526/btl-game)

---

# 🧹 Giới thiệu

**Fruit Cut** là một trò chơi mini mô phỏng cảm giác chém trái cây bằng chuột. Được phát triển bằng ngôn ngữ **C++** kết hợp thư viện **SDL2**, trò chơi mang lại trải nghiệm giải trí vui nhộn, kịch tính và phù hợp với mọi lứa tuổi.

---

# 🗂️ Cấu trúc dự án

```
├── asset/               # Chứa hình ảnh, âm thanh, font
├── header/              # Các file header (.h) định nghĩa lớp và hàm
├── src/                 # Mã nguồn chính (.cpp)
│   ├── GameObject.cpp
│   ├── System.cpp
│   ├── effects(hitbomb).cpp
│   ├── game_score.cpp
│   ├── game_timer.cpp
│   ├── main.cpp
│   ├── menu.cpp
│   └── text.cpp
├── game.exe             # File thực thi (Windows)
├── highscore.txt        # File lưu điểm cao
├── SDL2_*.dll           # Các thư viện SDL2 cần thiết
├── .vscode/, MinGW/     # Cấu hình và trình biên dịch
```

---

##  Tính năng nổi bật


✂️ Gameplay cắt trái cây: Click chuột vào trái cây để chém. Mỗi quả bị chém sẽ tăng điểm.

💣 Bom nguy hiểm: Nếu click trúng bom, trò chơi kết thúc ngay lập tức.

🕒 Giới hạn thời gian: Trò chơi diễn ra trong 120 giây. Hãy tận dụng thời gian để đạt điểm cao nhất!

🔊 Âm thanh sống động: Âm thanh cắt trái cây, nổ bom và nhạc nền tạo trải nghiệm hấp dẫn.

🖥️ Giao diện người dùng: Menu chính, hướng dẫn chơi, và bảng điểm được thiết kế trực quan.

🧠 Quản lý điểm số & thời gian: Điểm được tính và hiển thị liên tục. Đồng hồ đếm ngược giúp người chơi theo dõi thời gian còn lại.

---
## Luật chơi
Trái cây và bom xuất hiện ngẫu nhiên từ dưới lên.

Click chuột vào trái cây để cắt và ghi điểm.

Click trúng bom sẽ khiến trò chơi kết thúc ngay lập tức.

Khi hết 120 giây, trò chơi kết thúc và hiển thị tổng điểm.


### 🛠️ Cài đặt và chạy game

# Yêu cầu:

* HĐH: **Windows** (có file `.exe`) hoặc **Linux**
* Cần các thư viện:

  * `SDL2`
  * `SDL2_image`
  * `SDL2_mixer`
  * `SDL2_ttf`

# Hướng dẫn:

```bash
git clone https://github.com/pHung526/btl-game.git
cd btl-game

# Biên dịch (Linux)
g++ src/*.cpp -o fruitcut -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Chạy game
./fruitcut       # Linux
game.exe         # Windows
```
---

## 📚 Tham khảo

* **SDL Tutorials:** [Lazy Foo'](https://lazyfoo.net/tutorials/SDL/)
* **Đồ họa:** [OpenGameArt.org](https://opengameart.org)
* **Âm thanh:** [Mixkit](https://mixkit.co), [Freesound](https://freesound.org)
* **Slash Effect:** Kenney Asset Pack

---

## 🧠 Mong muốn điểm: **8.0 - 8.5**
✓ Thêm nhiều texture trái cây, bom.

✓ Âm thanh khi cắt trái cây, khi nổ bom.

✓ Nhạc nền trong game.

✓ Hiệu ứng nổ bom (đổi texture + play sound).

✓ Màn hình menu, end screen, điểm cao.

✓ Đếm ngược 120 giây.


---

## 🪪 Giấy phép

Phát hành theo [MIT License](LICENSE)
