const addBtn = document.getElementById("addBtn");
const taskInput = document.getElementById("taskInput");
const taskList = document.getElementById("taskList");

let tasks = JSON.parse(localStorage.getItem("tasks")) || [];

function renderTasks() 
{
    taskList.innerHTML = "";
    tasks.forEach(function(task, index) 
    {
        const li = document.createElement("li");
        li.textContent = task.text;
        li.addEventListener("click", function()
        {
            tasks[index].done = !tasks[index].done;
            localStorage.setItem("tasks", JSON.stringify(tasks));
            renderTasks();
        });
        if (task.done)
        {
            li.style.textDecoration = "line-through";
            li.style.opacity = "0.5";
        }
        taskList.appendChild(li);
    });
}

addBtn.addEventListener("click", function()
{
    const taskText = taskInput.value;
    tasks.push({ text: taskText, done: false});
    localStorage.setItem("tasks", JSON.stringify(tasks));
    renderTasks();
    taskInput.value = "";
});

renderTasks();