var totalFrames = 1;
var currentFrame = 1;
var frames = [];
var delta = {
    x: 0,
    y: 0
};

var currentFrameElement = null;
var totalFramesElement = null;

function addArrowKeyNavigation() {
    const cells = document.querySelectorAll('.cell input');
    cells.forEach((cell, i) => {
        cell.addEventListener('keydown', (e) => {
            let targetCell;
            const numCells = document.querySelector('.grid-row').children.length;
            switch (e.key) {
                case 'ArrowUp':
                    targetCell = cells[i - numCells];
                    break;
                case 'ArrowDown':
                    targetCell = cells[i + numCells];
                    break;
                case 'ArrowLeft':
                    targetCell = cells[i - 1];
                    break;
                case 'ArrowRight':
                    targetCell = cells[i + 1];
                    break;
            }
            if (targetCell) {
                e.preventDefault();
                targetCell.focus();
            }
        });
    });
}

document.addEventListener('DOMContentLoaded', () => {
    const addRowBtn = document.getElementById('addRowBtn');
    const removeRowBtn = document.getElementById('removeRowBtn');
    const addColumnBtn = document.getElementById('addColumnBtn');
    const removeColumnBtn = document.getElementById('removeColumnBtn');
    const clearGridBtn = document.getElementById('clearGridBtn');

    addRowBtn.addEventListener('click', () => addRow());
    removeRowBtn.addEventListener('click', () => removeRow());
    addColumnBtn.addEventListener('click', () => addColumn());
    removeColumnBtn.addEventListener('click', () => removeColumn());
    clearGridBtn.addEventListener('click', () => clearGrid());

    const addFrameBtn = document.getElementById('addFrameBtn');
    const delFrameBtn = document.getElementById('delFrameBtn');
    const nextFrameBtn = document.getElementById('nextFrameBtn');
    const prevFrameBtn = document.getElementById('prevFrameBtn');

    addFrameBtn.addEventListener('click', () => addFrame());
    delFrameBtn.addEventListener('click', () => delFrame());
    nextFrameBtn.addEventListener('click', () => nextFrame());
    prevFrameBtn.addEventListener('click', () => prevFrame());

    const startAnimationBtn = document.getElementById('startAnimationBtn');
    const stopAnimationBtn = document.getElementById('stopAnimationBtn');

    startAnimationBtn.addEventListener('click', () => startAnimation());
    stopAnimationBtn.addEventListener('click', () => stopAnimation());
});

function clearGrid() {
    console.log("clearing grid");
    const cells = document.querySelectorAll('.cell input');
    cells.forEach(cell => {
        cell.value = '';
    });

    saveFrame();
    updatePreview();
    addArrowKeyNavigation();
}

function addRow() {
    const gridContainer = document.getElementById('grid-container');
    const firstRow = gridContainer.querySelector('.grid-row');
    const numCells = firstRow.children.length;

    const newRow = document.createElement('div');
    newRow.className = 'grid-row';

    for (let i = 0; i < numCells; i++) {
        const cell = document.createElement('div');
        cell.className = 'cell';
        const input = document.createElement('input');
        input.setAttribute('type', 'text');
        input.setAttribute('maxlength', '1');
        input.addEventListener('input', handleInputChange);
        cell.appendChild(input);
        newRow.appendChild(cell);
    }

    gridContainer.appendChild(newRow);

    // saveGridState();
    saveFrame();
    updatePreview();
    addArrowKeyNavigation();
}

function removeRow() {
    const gridContainer = document.getElementById('grid-container');
    const rows = gridContainer.querySelectorAll('.grid-row');

    if (rows.length > 1) {
        gridContainer.removeChild(rows[rows.length - 1]);
    }

    // saveGridState();
    saveFrame();
    updatePreview();
    addArrowKeyNavigation();
}

function addColumn() {
    const rows = document.querySelectorAll('.grid-row');

    rows.forEach(row => {
        const cell = document.createElement('div');
        cell.className = 'cell';
        const input = document.createElement('input');
        input.setAttribute('type', 'text');
        input.setAttribute('maxlength', '1');
        input.addEventListener('input', handleInputChange);
        cell.appendChild(input);
        row.appendChild(cell);
    });

    // saveGridState();
    saveFrame();
    updatePreview();
    addArrowKeyNavigation();
}

function removeColumn() {
    const rows = document.querySelectorAll('.grid-row');

    rows.forEach(row => {
        const cells = row.querySelectorAll('.cell');

        if (cells.length > 1) {
            row.removeChild(cells[cells.length - 1]);
        }
    });

    // saveGridState();
    saveFrame();
    updatePreview();
    addArrowKeyNavigation();
}

function handleInputChange(event) {
    const input = event.target;
    const value = input.value.trim().toUpperCase();
    if (value.length > 1) {
        input.value = value.slice(0, 1);
    }

    // saveGridState();
    saveFrame();
    updatePreview();
    addArrowKeyNavigation();
}

function updatePreview() {
    const preview = document.getElementById('preview');
    const currentGrid = frames[currentFrame - 1];

    let previewText = '';

    currentGrid.forEach(row => {
        row.forEach(cell => {
            previewText += cell;
        });
        previewText += '\n';
    });

    preview.textContent = previewText;
}

function saveFrame() {
    const gridContainer = document.getElementById('grid-container');
    const rows = gridContainer.querySelectorAll('.grid-row');
    const currentGrid = [];

    rows.forEach(row => {
        const cells = row.querySelectorAll('.cell');
        const rowValues = [];

        cells.forEach(cell => {
            if (cell.querySelector('input').value === '') {
                rowValues.push(' ');
            }
            else {
                rowValues.push(cell.querySelector('input').value);
            }
        });

        currentGrid.push(rowValues);
    });

    frames[currentFrame - 1] = currentGrid;
    saveAllFrames();
}

function addFrame() {
    const gridContainer = document.getElementById('grid-container');
    const rows = gridContainer.querySelectorAll('.grid-row');
    const currentGrid = [];

    rows.forEach(row => {
        const cells = row.querySelectorAll('.cell');
        const rowValues = [];

        cells.forEach(cell => {
            if (cell.querySelector('input').value === '') {
                rowValues.push(' ');
            }
            else {
                rowValues.push(cell.querySelector('input').value);
            }
        });

        currentGrid.push(rowValues);
    });

    frames.splice(currentFrame - 1, 0, currentGrid);
    currentFrame++;
    totalFrames++;

    currentFrameElement.textContent = currentFrame;
    totalFramesElement.textContent = totalFrames;

    console.log(frames);
    saveAllFrames();
    loadCurrentFrame();
}

function delFrame() {
    console.log("deleting frame");

    if (totalFrames <= 1) {
        return;
    }

    frames.splice(currentFrame - 1, 1);
    totalFrames--;

    if (currentFrame > totalFrames) {
        currentFrame--;
    }

    currentFrameElement.textContent = currentFrame;
    totalFramesElement.textContent = totalFrames;

    console.log(frames);
    saveAllFrames();
    loadCurrentFrame();
}

function nextFrame() {
    if (currentFrame >= totalFrames) {
        currentFrame = 1;
    }
    else {
        currentFrame++;
    }

    currentFrameElement.textContent = currentFrame;
    loadCurrentFrame();
}

function prevFrame() {
    if (currentFrame <= 1) {
        currentFrame = totalFrames;
    }
    else {
        currentFrame--;
    }

    currentFrameElement.textContent = currentFrame;
    loadCurrentFrame();
}

function loadCurrentFrame() {
    const gridContainer = document.getElementById('grid-container');
    console.log("Frames: ", frames);
    const currentGrid = frames[currentFrame - 1];
    console.log("Current frame idx: ", currentFrame - 1);
    gridContainer.innerHTML = '';
    for (let i = 0; i < currentGrid.length; i++) {
        const row = document.createElement('div');
        row.className = 'grid-row';
        for (let j = 0; j < currentGrid[i].length; j++) {
            const cell = document.createElement('div');
            cell.className = 'cell';
            const input = document.createElement('input');
            input.setAttribute('type', 'text');
            input.setAttribute('maxlength', '1');
            input.addEventListener('input', handleInputChange);

            if (currentGrid[i][j] === ' ') {
                input.value = '';
            }
            else {
                input.value = currentGrid[i][j];
            }
            cell.appendChild(input);
            row.appendChild(cell);
        }
        gridContainer.appendChild(row);
    }

    addArrowKeyNavigation();
    updatePreview();
}

function loadAllFrames() {
    // frames from local storage needs to be array of grid states
    const savedFramesJson = localStorage.getItem('frames');

    if (!savedFramesJson) {
        // create a new frame
    }

    frames = JSON.parse(savedFramesJson);
    console.log(frames);

    totalFrames = frames.length;
    currentFrame = 1;

    currentFrameElement.textContent = currentFrame;
    totalFramesElement.textContent = totalFrames;
}

function saveAllFrames() {
    const framesJson = JSON.stringify(frames);
    localStorage.setItem('frames', framesJson);
}

window.onload = function () {
    // get saved frames
    currentFrameElement = document.getElementById('currentFrame');
    totalFramesElement = document.getElementById('totalFrames');

    const savedFramesJson = localStorage.getItem('frames');

    if (savedFramesJson) {
        const savedFrames = JSON.parse(savedFramesJson);
        console.log(savedFrames);
        frames = savedFrames;
        loadAllFrames();
    }
    else {
        frames = [[[' ']]];
        saveAllFrames();
    }

    addArrowKeyNavigation();
    loadCurrentFrame();
};

var animationInterval = null;

function startAnimation() {
    const animationTime = document.getElementById('animationTime').value;
    animationInterval = setInterval(nextFrame, animationTime);
}

function stopAnimation() {
    clearInterval(animationInterval);
}