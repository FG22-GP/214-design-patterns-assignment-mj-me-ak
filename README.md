[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# Which Witch Will Win

## Project Info
A local-mutltiplayer fighting game with support for animated spritesheets.

## Patterns used
- [Command](#command)
- [Observer](#observer)
- [Component](#component)
- [Game Loop](#game-loop-and-update-method)
- [Update Method](#game-loop-and-update-method)

### Command
- What does it do?
  - Input Handling
- Why was it chosen?
  - Easy to have [different](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/GameObjects/CommandManager.cpp#L12) input-schemes for the players
  - Easy to add more inputs with more Commands
- How was it implemented?
  - [Base Command](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/input.h#L13) class with a virtual Execute method
  - InputHandler instance which [returns](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/input.cpp#L39) a list of Commands
  - CommandManager [executes](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/GameObjects/CommandManager.cpp#L20) the list Commands on the players

### Observer
- What does it do?
- Why was it chosen?
- How was it implemented?

### Component
- What does it do?
- Why was it chosen?
- How was it implemented?

### Game Loop and Update Method
- What does it do?
- Why was it chosen?
- How was it implemented?
