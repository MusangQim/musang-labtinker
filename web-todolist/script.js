const addBtn = document.getElementById("addBtn");
const taskInput = document.getElementById("taskInput");
const taskList = document.getElementById("taskList");

let tasks = JSON.parse(localStorage.getItem("tasks")) || [];

function renderTasks() 
{
    taskList.innerHTML = "";
    tasks.forEach(function(task) 
    {
        const li = document.createElement("li");
        li.textContent = task;
        taskList.appendChild(li);
    })
}

addBtn.addEventListener("click", function()
{
    const taskText = taskInput.value;
    tasks.push(taskText);
    localStorage.setItem("tasks", JSON.stringify(tasks));
    renderTasks();
    taskInput.value = "";
});

renderTasks();