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

* 🎮 **Điều khiển mượt mà:** Chém trái cây bằng chuột, cảm giác slash sống động
* 💥 **Hiệu ứng hấp dẫn:** Hiệu ứng nước trái cây, bom nổ sinh động
* 🧠 **Chế độ chơi đa dạng:**

  * Arcade Mode:* Đua điểm trong thời gian giới hạn
  * Classic Mode:* Tránh bom, không được bỏ lỡ trái
* 🔊 **Âm thanh & giao diện:**

  * Menu dễ dùng, âm thanh sinh động
  * Có thanh điều chỉnh âm lượng
* 🧾 **Lưu điểm cao:** Ghi nhận điểm theo từng chế độ

---

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

* 🎉 **Gameplay cuốn hút**
* 🎨 **Giao diện đẹp, hiệu ứng tốt**
* 🔧 **Nhiều chế độ chơi, logic rõ ràng**
* 📈 **Hoàn thiện tốt, dễ mở rộng**

---

## 🪪 Giấy phép

Phát hành theo [MIT License](LICENSE)
