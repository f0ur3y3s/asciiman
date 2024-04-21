var totalFrames = 1;
var frameIndex = 1;
var frames = [{}];
var delta = {
    x: 0,
    y: 0
};

test = [{ grid: ['a', 'a', 'a'], offset_delta: { x: 0, y: 0 } }, {}];

var frameIndexElement = null;
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

    const offsetDeltaX = document.getElementById('offsetDeltaX');
    const offsetDeltaY = document.getElementById('offsetDeltaY');

    offsetDeltaX.addEventListener('input', () => saveFrame());
    offsetDeltaY.addEventListener('input', () => saveFrame());
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
    const currentGrid = frames[frameIndex - 1].grid;

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

    const deltaX = document.getElementById('offsetDeltaX').value;
    const deltaY = document.getElementById('offsetDeltaY').value;

    console.log("saving frame", frameIndex - 1, currentGrid, deltaX, deltaY);
    frames[frameIndex - 1].grid = currentGrid;
    frames[frameIndex - 1].offset_delta = { x: deltaX, y: deltaY };
    saveAllFrames();
}

function addFrame() {
    const currentFrame = JSON.parse(JSON.stringify(frames[frameIndex - 1]));

    frames.splice(frameIndex - 1, 0, currentFrame);
    frameIndex++;
    totalFrames++;

    frameIndexElement.textContent = frameIndex;
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

    frames.splice(frameIndex - 1, 1);
    totalFrames--;

    if (frameIndex > totalFrames) {
        frameIndex--;
    }

    frameIndexElement.textContent = frameIndex;
    totalFramesElement.textContent = totalFrames;

    console.log(frames);
    saveAllFrames();
    loadCurrentFrame();
}

function nextFrame() {
    if (frameIndex >= totalFrames) {
        frameIndex = 1;
    }
    else {
        frameIndex++;
    }

    frameIndexElement.textContent = frameIndex;
    loadCurrentFrame();
}

function prevFrame() {
    if (frameIndex <= 1) {
        frameIndex = totalFrames;
    }
    else {
        frameIndex--;
    }

    frameIndexElement.textContent = frameIndex;
    loadCurrentFrame();
}

function loadCurrentFrame() {
    const gridContainer = document.getElementById('grid-container');
    const currentGrid = frames[frameIndex - 1].grid;
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
    frameIndex = 1;

    frameIndexElement.textContent = frameIndex;
    totalFramesElement.textContent = totalFrames;
}

function saveAllFrames() {
    const framesJson = JSON.stringify(frames);
    localStorage.setItem('frames', framesJson);
}

window.onload = function () {
    frameIndexElement = document.getElementById('frameIndex');
    totalFramesElement = document.getElementById('totalFrames');

    const savedFramesJson = localStorage.getItem('frames');

    if (savedFramesJson) {
        const savedFrames = JSON.parse(savedFramesJson);
        console.log(savedFrames);
        frames = savedFrames;
        loadAllFrames();
    }
    else {
        frames = [{ grid: [[' ']], offset_delta: { x: 0, y: 0 } }];
        frameIndexElement.textContent = frameIndex;
        totalFramesElement.textContent = totalFrames;
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