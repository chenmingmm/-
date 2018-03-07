@echo off
git add .
set /p var=输入提交日志
echo;
echo 提交日志: %var%
git commit -m %var%
git push origin master