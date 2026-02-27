#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <chrono>
#include "vector2d.h"

// Función para calcular bezier
vector2d calcularbezier(const vector2d& p0, const vector2d& p1, const vector2d& p2, float t) {
    vector2d l0 = p0.lerp(p1, t);
    vector2d l1 = p1.lerp(p2, t);
    return l0.lerp(l1, t);
}

// Función para animar las curvas
void animacion(
    sf::RenderWindow& window,
    std::vector<sf::Vertex>& curva,
    const vector2d& p0,
    const vector2d& p1,
    const vector2d& p2,
    sf::Color color,
    int pasos = 450
) {
    for (int i = 0; i <= pasos; i++) {
        float t = (float)i / (float)pasos;
        vector2d punto =calcularbezier(p0, p1, p2, t);

       {
        sf::Vertex vertice{sf::Vector2f(punto.getX(), punto.getY())};
        vertice.color = color;
        curva.push_back(vertice);
        }
         

        window.clear(sf::Color::Black);
        window.draw(curva.data(), curva.size(), sf::Points);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(0));
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "TATA");
    std::vector<sf::Vertex> curva;
    vector2d p0(0,0), p1(0,0), p2(0,0);

    // Cuerpo 
    p0.set(312.0f, 546.7f); 
    p1.set(210.1f, 525.7f);
    p2.set(64.0f, 346.7f);
    animacion(window, curva, p0, p1, p2, sf::Color::Red);

    p0.set(309.9f, 538.7f); 
    p1.set(437.3f, 538.7f); 
    p2.set(619.7f, 350.5f);
    animacion(window, curva, p0, p1, p2, sf::Color::Red);

    // Orejas 
    p0.set(618.7f, 349.7f); 
    p1.set(746.7f, 19.0f); 
    p2.set(332.8f, 257.9f);
    animacion(window, curva, p0, p1, p2, sf::Color::Red);

    p0.set(334.4f, 259.8f); 
    p1.set(38.4f, 93.0f); 
    p2.set(64.0f, 347.0f);
    animacion(window, curva, p0, p1, p2, sf::Color::Red);

    // Cabeza 
    p0.set(201.1f, 342.9f); 
    p1.set(240.0f, 342.9f); 
    p2.set(282.7f, 342.9f);
    animacion(window, curva, p0, p1, p2, sf::Color::Black);

    p0.set(480.0f, 342.9f); 
    p1.set(435.7f, 342.9f); 
    p2.set(390.4f, 342.6f);
    animacion(window, curva, p0, p1, p2, sf::Color::Black);

     p0.set(312.0f, 546.7f); 
     p1.set(311.0f, 542.0f); 
     p2.set(309.9f, 538.7f);
     animacion(window, curva, p0, p1, p2, sf::Color::Red);


    //Pierna derecha
    p0.set(437.3f, 538.3f); 
    p1.set(505.6f, 648.5f); 
    p2.set(456.5f, 656.0f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(456.5f, 656.0f); 
    p1.set(408.5f, 658.3f); 
    p2.set(406.4f, 603.4f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(405.3f, 603.8f);
    p1.set(437.3f, 769.5f); 
    p2.set(320.0f, 736.8f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(437.3f, 538.3f); 
    p1.set(380.0f, 536.0f); 
    p2.set(309.9f, 538.7f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    //Pierna izquierda
    p0.set(319.7f, 736.6f); 
    p1.set(313.2f, 728.4f); 
    p2.set(313.1f, 666.2f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(313.1f, 665.9f); 
    p1.set(311.7f, 728.3f); 
    p2.set(308.3f, 736.2f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(308.3f, 736.4f); 
    p1.set(205.3f, 761.9f); 
    p2.set(219.2f, 604.2f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(217.6f, 603.4f); 
    p1.set(213.9f, 660.6f); 
    p2.set(149.3f, 655.2f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(149.3f, 655.2f); 
    p1.set(104.5f, 637.3f); 
    p2.set(208.5f, 526.1f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);

    p0.set(208.5f, 526.1f); 
    p1.set(260.0f, 536.0f); 
    p2.set(312.0f, 546.7f);
    animacion(window, curva, p0, p1, p2, sf::Color::Blue);
   
    //Ojo izquierdo
    sf::Color negro(100, 100, 100);

    p0.set(199.8f, 381.1f); 
    p1.set(200.0f, 401.4f); 
    p2.set(229.3f, 405.7f);
    animacion(window, curva, p0, p1, p2, negro);

    p0.set(229.3f, 405.7f); 
    p1.set(260.1f, 401.9f); 
    p2.set(260.1f, 381.1f);
    animacion(window, curva, p0, p1, p2, negro);

    p0.set(199.8f, 380.9f); 
    p1.set(203.6f, 363.0f); 
    p2.set(229.3f, 361.9f);
    animacion(window, curva, p0, p1, p2, negro);

    p0.set(260.1f, 381.1f); 
    p1.set(255.5f, 364.1f); 
    p2.set(229.3f, 361.9f);
    animacion(window, curva, p0, p1, p2, negro);

    //Ojo derecho 
    p0.set(400.0f, 381.0f); 
    p1.set(398.9f, 401.6f); 
    p2.set(429.9f, 401.9f);
    animacion(window, curva, p0, p1, p2, negro);

    p0.set(430.4f, 401.9f); 
    p1.set(453.7f, 401.1f); 
    p2.set(454.9f, 381.1f);
    animacion(window, curva, p0, p1, p2, negro);

    p0.set(454.8f, 381.1f); 
    p1.set(453.3f, 361.9f); 
    p2.set(426.7f, 361.9f);
    animacion(window, curva, p0, p1, p2, negro);

    p0.set(426.7f, 361.9f); 
    p1.set(400.0f, 361.9f); 
    p2.set(400.0f, 381.0f);
    animacion(window, curva, p0, p1, p2, negro);

    // Boca
    p0.set(248.0f, 424.0f); 
    p1.set(170.7f, 455.2f); 
    p2.set(256.0f, 480.0f);
    animacion(window, curva, p0, p1, p2, sf::Color::Yellow);

    p0.set(288.0f, 450.7f); 
    p1.set(320.0f, 451.2f); 
    p2.set(356.6f, 450.9f);
    animacion(window, curva, p0, p1, p2, sf::Color::Yellow);

    p0.set(397.9f, 478.5f); 
    p1.set(467.2f, 452.2f); 
    p2.set(406.5f, 428.2f);
    animacion(window, curva, p0, p1, p2, sf::Color::Yellow);

    p0.set(406.4f, 428.2f); 
    p1.set(326.1f, 404.0f); 
    p2.set(247.7f, 423.9f);
    animacion(window, curva, p0, p1, p2, sf::Color::Yellow);
    
    p0.set(256.0f, 480.0f); 
    p1.set(326.0f, 500.0f); 
    p2.set(397.9f, 478.5f);
    animacion(window, curva, p0, p1, p2, sf::Color::Yellow);

    // Loop principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color::White);
        window.draw(curva.data(), curva.size(), sf::Points);
        window.display();
    }

    return 0;
}