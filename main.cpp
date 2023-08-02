#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "textures.h"
using namespace std;

class Text {
private:
    bool mousePress = true;
    bool selectedGenre = false;

public:
    vector<sf::Text> textBoxes;
    void setText (sf::Text& text, sf::Font& font, const string& str, unsigned int characterSize, const sf::Color& fillColor) {
        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(characterSize);
        text.setFillColor(fillColor);
    }
    void outLineFunction (sf::RenderWindow& window, sf::Event event) {
        sf::RectangleShape outline;
        outline.setFillColor(sf::Color::Transparent);
        outline.setOutlineThickness(4.f);
        outline.setOutlineColor(sf::Color::Green);


        sf::Text& selected = textBoxes[-1]; // initializer

        for (const auto& i: textBoxes) {
            if (i.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                outline.setSize(sf::Vector2f(i.getGlobalBounds().width + 20.f, i.getGlobalBounds().height + 20.f));
                outline.setPosition(i.getPosition() - sf::Vector2f(4.f, 4.f));
                window.draw(i);
                window.draw(outline);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (mousePress) {
                        if (i.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            selectedGenre = true;
                            selected = i;
                        }
                        mousePress = false;
                    }
                }
                else if (event.type == sf::Event::MouseButtonReleased) {
                    mousePress = true;
                }
            }
            else {
                window.draw(i);
            }
        }
//        sf::String sfString = selected.getString();
//        std::string stdString = sfString.toAnsiString();
//        cout << stdString << endl;
        if (selectedGenre) {
            outline.setSize(sf::Vector2f(selected.getGlobalBounds().width + 20.f, selected.getGlobalBounds().height + 20.f));
            outline.setPosition(selected.getPosition() - sf::Vector2f(4.f, 4.f));
            window.draw(outline);
        }
    }

    void setAttributes(sf::Text& text) {

        if (selectedGenre) {

        }
    }
};

int main() {
    Text text;
    float width = 1500;
    float height = 1500;
    sf::RenderWindow window(sf::VideoMode(width, height), "Beat Builders");
    sf::Color lightGreen(162, 252, 162);

    sf::Font pixel;
    sf::Font semiBold;
    sf::Font otherPixel;

    pixel.loadFromFile("files/VPPixel-Simplified.otf");
    semiBold.loadFromFile("files/Panton-Trial-SemiBold.ttf");
    otherPixel.loadFromFile("files/Big Pixel demo.otf");

    sf::Sprite headphones;
    headphones.setScale(.20f, .20f);
    headphones.setTexture(TextureManager::GetTexture("headphones"));
    headphones.setPosition(width / 8.0f - 30, height / 5.0f - 175);

    sf::Text titleText;
    text.setText(titleText, pixel, "Create Your Playlist!", 90, sf::Color::Black);
    titleText.setStyle(sf::Text::Underlined);
    titleText.setPosition(width / 2.0f + 50, height / 4.0f - 200);

    sf::FloatRect titleRect = titleText.getLocalBounds();
    titleText.setOrigin(titleRect.left + titleRect.width/2.0f, titleRect.top  + titleRect.height/2.0f);

    sf::Text filterText;
    text.setText(filterText, semiBold, "Filters", 50, sf::Color::Black);
    filterText.setPosition(width / 7.0f, height / 4.0f - 65);

    sf::Text genreText;
    text.setText(genreText, otherPixel, "Select Your Genre", 50, sf::Color::Black);
    genreText.setPosition(width / 3.0f - 50, height / 4.0f - 100);

    sf::Text darkTrap;
    text.setText(darkTrap, otherPixel, "Dark Trap", 40, sf::Color::Black);
    darkTrap.setPosition(width / 9.0f - 50, height / 4.0f + 10);
    text.textBoxes.push_back(darkTrap);

    sf::Text hipHop;
    text.setText(hipHop, otherPixel, "Hip-Hop", 40, sf::Color::Black);
    hipHop.setPosition(width / 3.0f, height / 4.0f + 10);
    text.textBoxes.push_back(hipHop);

    sf::Text emo;
    text.setText(emo, otherPixel, "Emo", 40, sf::Color::Black);
    emo.setPosition(width / 2.0f + 125, height / 4.0f + 10);
    text.textBoxes.push_back(emo);

    sf::Text trapMetal;
    text.setText(trapMetal, otherPixel, "Trap Metal", 40, sf::Color::Black);
    trapMetal.setPosition(width / 2.0f + 350, height / 4.0f + 10);
    text.textBoxes.push_back(trapMetal);

    sf::Text rap;
    text.setText(rap, otherPixel, "Rap", 40, sf::Color::Black);
    rap.setPosition(width / 9.0f - 50, height / 3.0f - 20);
    text.textBoxes.push_back(rap);

    sf::Text underGround;
    text.setText(underGround, otherPixel, "Underground", 40, sf::Color::Black);
    underGround.setPosition(width / 3.0f - 50, height / 3.0f - 20);
    text.textBoxes.push_back(underGround);

    sf::Text rnb;
    text.setText(rnb, otherPixel, "RNB", 40, sf::Color::Black);
    rnb.setPosition(width / 2.0f + 125, height / 3.0f - 20);
    text.textBoxes.push_back(rnb);

    sf::Text pop;
    text.setText(pop, otherPixel, "Pop", 40, sf::Color::Black);
    pop.setPosition(width / 2.0f + 355, height / 3.0f - 20);
    text.textBoxes.push_back(pop);

    sf::Text reference;
    text.setText(reference, otherPixel, "", 40, sf::Color::Black);
    reference.setPosition(width / 2.0f + 355, height / 3.0f - 20);
    text.textBoxes.push_back(reference);

    sf::Text attributes;
    text.setText(attributes, otherPixel, "Enter Your Range (0.0 least, 1.0 most)", 35, sf::Color::Black);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(lightGreen);
        window.draw(titleText);
        window.draw(genreText);
        window.draw(headphones);
        text.outLineFunction(window, event);
        window.display();
    }

    return 0;
}
