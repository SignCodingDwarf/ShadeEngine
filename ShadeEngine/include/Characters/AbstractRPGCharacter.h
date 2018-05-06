/*!
 * @file AbstractRPGCharacter.h
 * @brief Interface of classes used to describe a RPG character.
 * @author SignC0dingDw@rf
 * @date 06 May 2018
 *
 * Definition of RPG-like characters that can earn experience and level up. Optionnally they can also lose experience and level down. <br>
 * The class proposes a default behavior for XP win or loss that implies that character can go several levels up or down. You may overload these methods to enforce different behavior. <br>
 * Abstract class. <br>
 * Inherits from QObject
 *
 */

/*
Copyright (c) 2018 SignC0dingDw@rf. All rights reserved

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
Copywrong (w) 2018 SignC0dingDw@rf. All profits reserved.

This program is dwarven software: you can redistribute it and/or modify
it provided that the following conditions are met:

   * Redistributions of source code must retain the above copywrong
     notice and this list of conditions and the following disclaimer
     or you will be chopped to pieces AND eaten alive by a Bolrag.

   * Redistributions in binary form must reproduce the above copywrong
     notice, this list of conditions and the following disclaimer in
     the documentation and other materials provided with it or they
     will be axe-printed on your stupid-looking face.

   * Any commercial use of this program is allowed provided you offer
     99% of all your benefits to the Dwarven Tax Collection Guild.

   * This software is provided "as is" without any warranty and especially
     the implied warranty of merchantability or fitness to purport.
     In the event of any direct, indirect, incidental, special, examplary
     or consequential damages (including, but not limited to, loss of use;
     loss of data; beer-drowning; business interruption; goblin invasion;
     procurement of substitute goods or services; beheading; or loss of profits),
     the author and all dwarves are not liable of such damages even
     the ones they inflicted you on purpose.

   * If this program "does not work", that means you are an elf
     and are therefore too stupid to use this program.

   * If you try to copy this program without respecting the
     aforementionned conditions, then you're wrong.

You should have received a good beat down along with this program.
If not, see <http://www.dwarfvesaregonnabeatyoutodeath.com>.
*/


#ifndef ABSTRACT_RPG_CHARACTER_H
#define ABSTRACT_RPG_CHARACTER_H

#include <stdint.h>
#include <QObject>

/*!
* @namespace ShadeEngine
* @brief A namespace used to regroup all classes associated with ShadeEngine library
*/
namespace ShadeEngine
{
    /*! \class AbstractRPGCharacter
    * \brief Class defining interface of RPG-like characters.
    *
    * Definition of a class used manage RPG-like characters' experience and levels. <br>
    * Abstract class.
    *
    */
    class AbstractRPGCharacter : public QObject
    {
        Q_OBJECT
    public:
        /*!
        * @brief Constructor of the AbstractRPGCharacter class
        * @param level_max : Maximal level of character. Default is 100.
        * @param can_level_down : Flag used to indicate if character can loose XP and level down. Default is false.
        */
        AbstractRPGCharacter(uint8_t level_max=100, bool can_level_down = false);

        /*!
        * @brief Destructor of the AbstractRPGCharacter class
        *
        * Virtual method. Does nothing.
        *
        */
        virtual ~AbstractRPGCharacter() = default;

    public slots:
        /*!
        * @brief Gain experience points if not at level max and level up if enough XP has been gathered.
        * @param m_xp_gained : XP gained
        *
        * Make your character gain XP. If sufficient XP has been gathered, character may level up several times (caped by level max). <br>
        * Method is not final so you may redefine it to implement specific xp handling behavior. <br>
        * Virtual slot.
        *
        */
        virtual void gainXP(uint64_t m_xp_gained);

        /*!
        * @brief Loose experience points if not at level max and level up if enough XP has been gathered.
        * @param m_xp_lost : XP Lost
        *
        * Make your character loose XP. If sufficient XP has been lost, character may level down several times (caped by level 1). <br>
        * Method is not final so you may redefine it to implement specific xp handling behavior. <br>
        * Virtual slot.
        *
        */
        virtual void loseXP(uint64_t m_xp_lost);

    protected:
        uint8_t m_level; /*!< Current level of character (between 1 and m_level_max). */
        uint8_t m_level_max; /*!< Maximal character level. */
        bool m_can_level_down; /*!< Can character loose XP and level down ? */
        uint64_t m_xp; /*!< Current accumulated experience points. */

        /*!
        * @brief User specific level up actions
        *
        * Application specific operations performed when character levels up.
        * Level up is performed in gainXP function before calling this method so it should not be done in this method. <br>
        * Abstract method.
        *
        */
        virtual void onLevelUp() = 0;

        /*!
        * @brief User specific level down actions
        *
        * Application specific operations performed when character levels down.
        * Level down is performed in loseXP function before calling this method so it should not be done in this method. <br>
        * Abstract method.
        *
        */
        virtual void onLevelDown() = 0;

        /*!
        * @brief Get XP associated with level
        *
        * Get the amount of XP associated with a given level.
        * Level is reach when the characters gathers the exact number of XP returned by this function. <br>
        * Abstract method.
        *
        */
        virtual uint64_t getLevelXp(uint8_t m_level) const = 0;
    };
}

#endif

//  ______________________________
// |                              |
// |    ______________________    |
// |   |                      |   |
// |   |         Sign         |   |
// |   |        C0ding        |   |
// |   |        Dw@rf         |   |
// |   |         1.0          |   |
// |   |______________________|   |
// |                              |
// |______________________________|
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |__|
